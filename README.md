# ECS 150: Project #2 - User-level thread library #
 
## Contributors ##
Robert St. Denis & Liem Nguyen

## Design Choices ##
Overall, our uthread library `libuthread.a` was implemented with code readability and program efficiency in mind. No header files were added or modified to ensure high-quality coding practice was maintained, and nearly every line has been neatly commented for ease of understanding. 

Our queue API uses a circular queue for robustness with head and tail pointers as well as a length property. All queue functions excluding `queue_iterate()` and `queue_delete()` are *O(1)*. 

Our key design choice in `uthread.c` was to use an array of global queues rather than two individual queues and a pointer to the running thread. Not only did this result in higher frequency use of the `queue_` functions, but the exit logic of our `uthread_start()` loop can be implemented in a single line:

``` c
while(queue_length(ReadyQ)) 	uthread_yield();
``````
`uthread.c` was also thoroughly checked for memory leaks using tests 1-5, and all queues are deallocated and freed without error at the end of `uthread_start()`.

All threads also maintain a `uthread_state_t` typdef'd as an enum with 4 unique states. The uthead_tcb structure is shown below.
``` c
struct uthread_tcb {
    uthread_state_t state;                              /* Holds the thread's state                 */
    uthread_func_t func;                                /* Pointer to thread function               */
    uthread_ctx_t *uctx;                                /* User level thread context                */
    sigset_t *sigset;                                   /* Used for saving the preemption state     */
    void *arg;                                          /* Pointer to thread function arg           */
    void *stack;                                        /* Pointer to the top of the threads' stack */
}
``````

`semaphore.c` is both straightforward and brief. The semaphore structure holds only a single `size_t` and a `queue_t` of blocked threads.

`preempt.c` is brief, but contains some very specific design choices. Our idea behind preempt_save() and preempt_restore() was not only to ensure that the current thread's signal mask would be saved, but also that the current value of the timer would be saved. Since the save and restore functions only have access to a single sigset_t pointer, we used bitwise operations to store and extact the current timer value within the mask. This only works however, under the circumstances that we only care about the `

## Additional Files ##
`rmake.sh` - A remote compile script for compiling on CSIF. Uses 'rsync' and 'ssh' to sync the project folder and remotely compile on the CSIF machines.

`ExampleFiles` - Directory containing instructor provided files and the assignment.

## A "Brief" Overview of libuthread.a ##
### Phase 1 - A Queue API ###
We first implemented a FIFO queue, by making modifications in queue.c. We defined the node and queue structures as typedefs, then defined the functions `queue_create()`, `queue_destroy()`, `queue_enqueue()`, `queue_dequeue()`, `queue_delete()`, `queue_iterate()`, and `queue_length()`. All implementations excluding `queue_iterate()` and `queue_delete()` are *O(1)*.

For `queue_create()`, a queue is malloc'd and if malloc fails, a NULL pointer is returned from the function. If malloc successeds the queue's head and tail are set to NULL, the length to zero, and the pointer is returned.

For `queue_destroy()`, a pointer to a queue is passed as an argument to the function which first proceeds to check for potential failures. The following situations result in failure: The queue passed is NULL, the head of the queue passed is not NULL, the tail of the queue is not NULL, and the length of the queue is not NULL. The purpose of the checks is to avoid destroying a queue that has not been properly cleared first. If none of these failures are reached, then we simply free the queue from memory, and return success.

For `queue_enqueue()`, a node is malloced and added to the queue, which is passed as a pointer to the function along with a void * pointer to the data to enqueue. If the queue pointer passed is NULL, or the malloc returns a NULL pointer for the node, the function returns a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. 

For `queue_dequeue()` removes a node from the queue. A pointer to queue structure is passed along with void double pointer to the data parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the value of the double pointer to be the data of the queue's head, by deferencing. Then, if we fail to remove the node from the queue by the queue_delete() function call, then we return a failure. If we succeed to remove the node from the queue, then we return a success.

For `queue_delete()`, a pointer to a queue structure and pointer to data are passed as parameters into the function. We first initialized two node pointers, a current node we intend to use, and a temporary node that may also be needed. If the queue or queue's head is NULL, we return a failure. Otherwise, we set our initialialized node pointer to point to the the queue's head so that we can start to iterate over the queue. If there are more items in the queue, and the current node's data is the data of the node we want to delete, then we set the temporary node as the next node after the current node, so that we can overrite by setting the data and next values of the current node to equal the data and next values of the following (temporary node). Once that's done, we need to free the temporary node to be safe, since we no longer need its allocation of memory. If the node was overwritten by a delete operation was the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.

For `queue_iterate()`, we pass a queue structure and queue function as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there exists a queue. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.

For queue_length, we simply pass a pointer to the queue structure as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0. Otherwise we simply return `queue->length`.

Finally, we completed the Makefile of our libuthread to successfully generate a library archive (.a) file, and we had to add other C files as we started implementing them from one phase to the next phase. We also built a test-queue.c that allows us to test our queue implementations in order.


### Phase 2 - Schedule the execution of threads in a round-robin fashion ###
We needed to implement most of the thread management in this phase of the program, which was done by making modifications in uthread.c file. We predefined 4 global pointers to the 4 queues (ready, run, wait, done) to represent the states of a thread during its lifetime. We also defined the set of registers for each state in order to save the thread for descheduling and later scheduling. We also clearly defined the thread control block (TCB) of a typical thread, including in its structure: the thread's state, a pointer to the thread function, a user-level thread context (for context switching), a signal set (for phase 4), and two pointers, one to the thread function's argument and one to the top of the thread function's stack. Lastly, we defined the functions uthread_enqueue, uthread_yield, uthread_init, uthread_create, uthread_exit, uthread_block, uthread_unblock, uthread_current, and uthread_start.

For uthread_enqueue, we pass a pointer to the thread control block (TCB) and the current state of the thread as parameters of the program. By setting the current state of the TCB to equal the state we passed in to the function, we could implement a switch statement to determine which thread state queue to place our TCB in.

For uthread_yield, we declare TCB pointers (next, run, done), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. If we can't remove the next thread from the ready state queue, then we remove the running thread from the run state queue, change state, then add the running thread to the ready state queue and add the next thread to the running state queue. Then we must do a thread context switch for threads that are running and ready, by suspending execution of a currently running thread and resuming execution of another thread. This is needed whenever we deal with multiple threads. From here, while there are finished threads that exist on the done state queue, we destroy their respective stacks and free all of their thread contexts, signal set object, and memory space, simply because we don't need them anymore.

For uthread_init, we pass a thread function and argument of that function as parameters to the function. We must allocate the right amount of memory for the TCB, as well as allocate thread context and signal set object. Then we assign the TCB's function pointer and argument pointer to the parameters we passed in, and set the TCB's current state to ready.

For uthread_create, we make a function call to uthread_init defined earlier to initialize the thread we intend to create. That comes with allocating memory for a stack and pointer to the top of the stack. Once we create our thread, we add it to the ready state queue.

For uthread_exit, we declare TCB pointers (me, next), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. We remove the running thread from the run state queue and remove the next thread from the ready state queue. Then we can change state and add the running and next threads to the done state queue and running state queue, respectively. Then we make the necessary thread context switch. There is no need to restore signal state and re-enable interrupts since we're exiting the thread life cycle.

For uthread_block, we declare TCB pointers (next, run), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts. We perform similar actions in this function as we do in uthread_exit. We remove the running thread from the run state queue and remove the next queue from the ready state queue. Then we change state and add the running and next threads from the WAITING state queue and running state queue, respectively. We add the running thread to the waiting state queue so that the thread can next transition to the running state queue. Then we make the necessary thread context switch. Lastly, we restore the signal state and re-enable the interrupts.

For uthread_unblock, we pass a thread as a parameter to the function. We also save the signal state and disable interrupts. We remove the blocked thread from the waiting state queue by calling queue_delete(), and then add that same thread onto the ready state queue. We then restore the signal state and re-enable the interrupts.

For uthread_current, we initialize a local thread structure (current). This function allows us to take hold of the current thread we are dealing with, and we call this function so that it returns us the current thread.

For uthread_start, we pass a thread start function and the argument of that function as parameters to the function. We must iterate through each of the 4 thread states (ready, run, wait, done), in order to see where to initialize our thread. Once we set the state of our thread and add it to the running state queue, we start the timer (*Phase 4*) and create the thread that we must add to the next queue, the ready state queue.  If a thread already exists, we can simply switch to the next thread by calling uthread_yield(). Lastly, we must conduct memory cleanup in order to assure no memory leak once we no longer need a thread.

Test 1 and 2 confirmed that our function definitions were implemented properly and effectively.


### Phase 3 - Provide a thread synchronization API, namely semaphores ###
In this phase we needed to implement semaphores, which would allow us(ers) to control access to the common resources by multiple threads. 

First we needed to properly define a semaphore structure, which contains the "count", the number of threads able to share a common resource at the same time, and waiting state queue, queue of threads waiting to use that resource. We defined the functions sem_create, sem_destroy, sem_down, and sem_up.

For sem_create, we passed the count as the parameter of the function. We must first allocate memory for our semaphore structure, and then create the waiting state queue of waiting threads, and initializing the count of the semaphore we just created.

For sem_destroy, we passed the semaphore structure as the parameter of the function. If we fail to destory the waiting state queue associated with the semaphore, we return a failure. If we succeed to destroy the waiting state queue, then we free its memory and return a success.

For sem_down, threads can ask to grab a resource, so we passed a semaphore structure as the parameter of the function. If the thread tries to grab a resource when the count is down to 0, it adds that thread to the list of threads in the waiting state queue. The thread is put in a blocked state and isn't eligible to scheduling.

For sem_up, threads can release a resource, so we passed a semaphore structure as the parameter of the function. If the thread releases a semaphore which count is 0, it needs to check whether threads exist on the waiting state queue. If so, the first thread of the waiting state queue can be unblocked and ran.

Test 3, 4, and 5 confirmed that our function definitions were implemented properly and effectively.


### Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler ###
In this final phase we needed to add a preemption to our user-thread library, by making modifications primarily in preempt.c, but also in other .c files under the libuthread sub-directory. We first needed to predefine the structure for the timer disabler. The functions we defined in preempt.c are preempt_save, preempt_restore, preempt_enable, preempt_disable, preempt_disabled, and timer_handler.

For preempt_save, we pass the "level" signal set as the parameter of the function. We first call sigprocmask(), which allows us mask the interrupt and block the signal call. Then we get the remaining time on the clock by calling getitimer(). We set the amount of time we have left to 0x2000000 and save the time left inside the current signal set we passed in as a parameter. Then we disable the timer, which successfully completes our call to preempt_save to save the time left inside the current signal set "level". 

For preempt_restore, we pass the "level" signal set as the parameter of the function. We essentially need to restore the amount of time that is left after extraction, by enabling preemption to pause the ongoing storage of remaining time. Once we enable, we can un-mask the interrupt and restore the time left inside the current signal set "level".

For preempt_enable, if we succesfully enable the timer value of restoreTimer and restore the time if it has been saved, then the function call has done its job.

For preempt_disable, if we successfully disable the timer value of disableTimer, then the function call has done its job.

For preempt_disabled, we simply check if the preemption is currently disabled.

For timer_handler, we can force the currently running thread to yield in order for another thread to be scheduled instead by calling uthread_yield().

If the outputs for test 1-5 are the same while running preempt.c with our modifications, then we know our function implementations were successful, which they were.

## Building / Running ##
This program was compiled using the Linux gcc 6.3.1 compiler.

To build, clone this repository and then cd to the folder in a terminal.

Then type `make` and let the `Makefile` and `libuthread/Makefile` do the rest.

After building, tests 1 through 5 can be run by typing `./testX`
where X represents the test number.

# References #
1. Operating Systems Principles and Practice (Chapter 4).
2. Man page for sigsetops

