% ECS 150: Project #2 - User-level thread library

# General information
We approached each phase individually, from the beginning stages of phase 1, to the final stages of phase 4.

## Phase 1 - Creating new execution threads.
We first implemented a FIFO queue, by making modifications in queue.c. We defined the node and queue structures, then defined the functions queue_create, queue_destroy, queue_enqueue, queue_dequeue, queue_delete, queue_iterate, and queue_length.

=> For queue_create, we first allocated memory space for a queue we locally initialize. If we failed to allocate proper memory space for our initialization, we would return NULL for the function call. If we succeded to allocate proper memory space for our initialization, then we set the queue head to NULL, tail to NULL, and length to 0. Then we return the initialized queue.
=> For queue_destroy, we pass a queue structure as a parameter into our function. If the queue is NULL, we return a failure. If the head of the queue is not NULL, we return a failure. If the tail of the queue is not NULL, we return a failure. If the length of the queue is not NULL, we return a failure. Essentially we don't want to destroy a queue that is not empty. If none of these failures are reached,  then we simply free the queue, and return a success.
=> For queue_enqueue, we need to push a node onto the queue. We pass a queue structure and data pointer as parameters into our function. We first allocated memory space for a node we locally initialize. If we failed to allocate proper memory space for our initialization, we would return a failure. If the queue we passed in as a parameter was NULL, we would also return a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. 
=> For queue_dequeue, we need to remove a node from the queue. We pass a queue structure and data double pointer as parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the data double pointer we passed in to equal to the data of the queue's head, by deferencing. Then, if we fail to remove the node from the queue by the queue_delete() function call, then we return a failure. If we succeed to remove the node from the queue, then we return a success.
=> For queue_delete, we pass a queue structure and data pointer as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the queue or queue's head is NULL, we return a failure. Else, we set our initialized current node to equal the queue's head, so we can start to iterate over the queue. If there are more items in the queue, and the current node's data is the data of the node we want to delete, then we set the temporary node as the next node after the current node, so that we can overrite by setting the data and next values of the current node to equal the data and next values of the following (temporary node). Once that's done, we need to free the temporary node to be safe, since we no longer need its allocation of memory. If the node we overrited (deleted) was the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.
=> For queue_iterate, we pass a queue structure and queue function as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there exists a queue. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.
=> For queue_length, we simply pass a queue structure as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0.

Lastly, we completed the makefile of our libuthread so we can successfully generate a library archive, and we had to add other C files as we started implementing them from one phase to the next phase. We also built a test-queue.c that allows us to test our queue implementations in order.


## Phase 2 - Schedule the execution of threads in a round-robin fashion



## Phase 3 - Provide a thread synchronization API, namely semaphores
## Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler



## Phase 2: thread API

In this second phase, you must implement most of the thread management (some is
provided to you for free). The interface to this thread API is defined in
`libuthread/uthread.h` and your code should be added into
`libuthread/uthread.c`.

Note that the thread API is actually composed of two sets: a public API and a
private API, as explained below.

### Thread definition

Threads are independent execution flows that run concurrently in the address
space of a single process (and thus, share the same heap memory, open
files, process identifier, etc.). Each thread has its own execution context,
which mainly consists of:

1. a state (running, ready, blocked, etc.)
1. the set of CPU registers (for saving the thread upon descheduling and
   restoring it later)
1. a stack

The goal of a thread library is to provide applications that want to use threads
an interface (i.e. a set of library functions) that the application can use to
create and start new threads, terminate threads, or manipulate threads in
different ways.

For example, the most well-known and wide-spread standard that defines the
interface for threads on Unix-style operating systems is called *POSIX thread*
(or `pthread`). The pthread API defines a set of functions, a subset of which we
want to implement for this project. Of course, there are various ways in which
the pthread API can be realized, and existing libraries have implemented pthread
both in the OS kernel and in user mode. For this project, we aim to implement a
few pthread functions at user level on Linux.

### Public API

The public API of the thread library defines the set of functions that
applications and the threads they create can call in order to interact with the
library.

From the point of view of applications, threads are designated by a number of
type `uthread_t`. Think of it as the equivalent of `pid_t` for Unix processes.

The first function an application has to call in order to initialize your
library is `uthread_start()`. This function must perform three actions:

1. It registers the so-far single execution flow of the application as the
   *idle* thread that the library can schedule
1. It creates a new thread, the *initial thread*, as specified by the arguments
   of the function
1. The function finally execute an infinite loop which
    1. When there are no more threads which are ready to run in the system, it
       stops the idle loop and exits the program.
    1. Or it simply yields to next available thread

Once the *initial thread* created, it can interact with the library to create
new threads, exit, yield execution, etc.

For this step, we expect the library to be non-preemptive. Threads must call the
function `uthread_yield()` in order to ask the library's scheduler to schedule
the next available thread. In non-preemptive mode, a non-compliant thread that
never yields can keep the processing resource for itself.

### Private API

The private API of the thread library defines the set of functions that can only
be accessed from the code of the library itself, and not by applications using
the library.

In order to deal with the creation and scheduling of threads, you first need a
data structure that can store information about a single thread. This data
structure will likely need to hold, at least, information mentioned above such
as the state of the thread (its set of registers), information about its stack
(e.g., a pointer to the thread's stack area), and information about the status
of the thread (whether it is running, ready to run, or has exited).

This data structure is often called a thread control block (*TCB*) and will be
described by `struct uthread_tcb`.

At this point, the functions defined in the private API could theoretically be
only defined in `libuthread/uthread.c` and not exported to the rest of the
library. But with the implementation of the semaphore API, semaphores will need
to have access to these functions in order to manipulate the thread when
necessary.

### Internal `context` API

Some code located in `libuthread/context.c`, and which interface is defined in
`libuthread/context.h`, is accessible for you to use. The four functions
provided by this library allow you to:

- Allocate a stack when creating a new thread (and conversely, destroy a stack
  when a thread is deleted)
- Initialize the stack and the execution context of the new thread so that it
  will run the specified function with the specified argument
- Switch between two execution contexts

### Testing

Two applications can help test this phase:
- `test1`: creates a single thread that displays "hello world"
- `test2`: creates three threads in cascade and test the yield feature of the
  scheduler

## Phase 3: semaphore API

Semaphores are a way to control the access to common resources by multiple
threads.

Internally, a semaphore has a certain count, that represent the number of
threads able to share a common resource at the same time. This count is
determined when initializing the semaphore for the first time.

Threads can then ask to grab a resource (known as "down" or "P" operation) or
release a resource (known as "up" or "V" operation).

Trying to grab a resource when the count of a semaphore is down to 0 adds the
requesting thread to the list of threads that are waiting for this resource. The
thread is put in a blocked state and shouldn't be eligible to scheduling.

When a thread releases a semaphore which count was 0, it checks whether some
other threads were currently waiting on it. In such case, the first thread of
the waiting list can be unblocked and run.

As you can now understand, your semaphore implementation will make use of the
functions defined in the private thread API.

The interface of the semaphore API is defined in `libuthread/semaphore.h` and
your implementation should go in `libuthread/semaphore.c`.

### Testing

Three testing programs are available in order to test your semaphore
implementation:

- `test3`: simple test with two threads and two semaphores
- `test4`: producer/consumer exchanging data in a buffer
- `test5`: prime sieve implemented with a growing pipeline of threads (this test
  really stresses both the thread management and the semaphore part of the
  library)

## Phase 4: preemption

Up to this point, uncooperative threads could keep the processing resource for
themselves if they never called `uthread_yield()` or never blocked on a
semaphore.

In order to avoid such dangerous behaviour, you will add preemption to your
library. The interface of the preemption API is defined in
`libuthread/preempt.h` and your code should be added to `libuthread/preempt.c`.

The function that sets up preemption, `preempt_start()`, is already provided for
you to call when you start the thread library. This function configures a timer
which will fire an alarm (through a `SIGVTALRM` signal) a hundred times per
second.

Internally, you must provide a timer handler which will force the currently
running thread to yield, so that another thread can be scheduled instead.

The other functions that you must implement deal with:
- enabling/disabling preemption
- saving/restoring preemption (saving means that the current preemption state
  must be saved and preemption must be disabled; restoring that the previously
  saved preemption state must be restored)
- checking if preemption is currently disabled

### About disabling preemption...

Preemption is a great way to enable reliable and fair scheduling of threads, but
it comes with some pitfalls.

For example, if the library is accessing sensitive data structures in order to
add a new thread to the system and gets preempted in the middle, scheduling
another thread of execution that might also manipulate the same data structures
can cause the internal share state of the library to become inconsistent.

Therefore, when manipulating shared data structures, preemption should probably
be temporarily disabled so that such manipulations are guaranteed to be
performed *atomically*.

However, avoid disabling preemption each time a thread calls the library. Try to
disable preemption only when necessary. For example, the creation of a new
thread can be separated between sensitive steps that need to be done atomically
and non-sensitive steps that can safely be interrupted and resumed later without
affecting the consistency of the shared data structures.

A good way to figure out whether preemption should be temporarily disabled while
performing a sequence of operations is to imagine what would happen if this
sequence was interrupted in the middle and another thread scheduled.

As a hint, in the reference implementation, the preempt API is used in the
following files:

```
$ grep -l preempt_* libuthread/*.c | uniq
libuthread/preempt.c
libuthread/semaphore.c
libuthread/uthread.c
libuthread/context.c
```

# Deliverable

## Constraints

Your library must be written in C, be compiled with GCC and only use the
standard functions provided by the GNU C Library. It cannot be linked to any
other external libraries.

Your source code should follow the relevant parts of the [Linux kernel coding
style](https://www.kernel.org/doc/html/latest/process/coding-style.html) and be
properly commented.

## Content

Your submission should contain, besides your source code, the following files:

- `AUTHORS`: full name, student ID and email of each partner, one entry per
  line formatted in CSV (fields are separated with commas). For example:

    ```
    $ cat AUTHORS
    Jean Dupont,00010001,jdupont@ucdavis.edu
    Marc Durand,00010002,mdurand@ucdavis.edu
    ```

- `REPORT.md`: a
  [markdown-formatted](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
  file containing a description of your submission.

    This file should explain your design choices, how you tested your project,
    the sources that you may have used to complete this project, etc. and any
    other relevant information.

## Git

Your submission must be under the shape of a Git bundle. In your git repository,
type in the following command (your work must be in the branch `master`):

```
$ git bundle create uthread.bundle master
```

It should create the file `uthread.bundle` that you will submit via `handin`.

You can make sure that your bundle has properly been packaged by extracting it
in another directory and verifying the log:

```
$ cd /path/to/tmp/dir
$ git clone /path/to/uthread.bundle -b master uthread
$ cd uthread
$ git log
...
```

## Handin

Your Git bundle, as created above, is to be submitted with `handin` from one of
the CSIF computers:

```
$ handin cs150 p2 uthread.bundle
Submitting uthread.bundle... ok
$
```

You can verify that the bundle has been properly submitted:

```
$ handin cs150 p2
The following input files have been received:
...
$
```

# Academic integrity

You are expected to write this project from scratch, thus avoiding to use any
existing source code available on the Internet. You must specify in your
`README.md` file any sources of code that you or your partner have viewed to
help you complete this project. All class projects will be submitted to MOSS to
determine if pairs of students have excessively collaborated with other pairs.
Excessive collaboration, or failure to list external code sources will result in
the matter being transferred to Student Judicial Affairs.

