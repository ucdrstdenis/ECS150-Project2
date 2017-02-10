# ECS 150: Project #2 - User-level thread library #
 
## Contributors ##
Robert St. Denis & Liem Nguyen

## Design Choices ##
Overall, our uthread library `libuthread.a` was implemented with code readability and program efficiency in mind. No header files were added or modified to ensure high-quality coding practice was maintained, and nearly every line has been neatly commented for ease of understanding. 

Our queue API uses a circular queue for robustness with head and tail pointers as well as a length property. All queue functions excluding `queue_iterate()` and `queue_delete()` are *O(1)*. 

Our key design choice in `uthread.c` was to use an array of global queues rather than two individual queues and a pointer to the running thread. Not only did this result in higher frequency use of the `queue_` functions, but the exit logic of our `uthread_start()` loop can be performed in a single line:

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

`preempt.c` is brief, but contains some very specific design choices. Our idea behind `preempt_save()` and `preempt_restore()` was not only to ensure that the current thread's signal state would be saved, but also that the current value of the timer would be saved. Since the save and restore functions only have access to a single sigset_t pointer, we used bitwise operations to store and extact the current timer value within the mask. This only works however, under the circumstances that `SIGVTALRM` is the only signal of interest, and that the timer value is not set much larger than the required 10000 microseconds (Or else it could potentially conflict with the mask value of `0x2000000`);

Masking is performed via the `sigprocmask()` function. When `preempt_save()` is called, the interrupt is masked to prevent the critical section from being interrupted. The mask value and current timer value are stored in the thread's `sigset_t->__val[0]`. Finally, `preempt_save()` calls `preempt_disable()` which uses the `setitimer()` function to fully disable the timer. The interrupt is not unmasked until after the timer has been re-enabled with the restored value extracted in `preempt_restore()`. (If `preempt_enable()` is called directly, the restored value is simply the full value of 10,000 microseconds).

## Additional Files ##
`rmake.sh` - A remote compile script for compiling on CSIF. Uses 'rsync' and 'ssh' to sync the project folder and remotely compile on the CSIF machines.

`ExampleFiles` - Directory containing instructor provided files and the assignment.

## A Highly Detailed Overview of libuthread.a ##
### Phase 1 - A Queue API ###
We first implemented a FIFO queue, by making modifications in `queue.c`. We defined the node and queue structures as typedefs, then defined the functions `queue_create()`, `queue_destroy()`, `queue_enqueue()`, `queue_dequeue()`, `queue_delete()`, `queue_iterate()`, and `queue_length()`. All implementations excluding `queue_iterate()` and `queue_delete()` are *O(1)*.

For `queue_create()`, a queue is malloc'd and if malloc fails, a NULL pointer is returned from the function. If malloc successeds the queue's head and tail are set to NULL, the length to zero, and the pointer is returned.

For `queue_destroy()`, a pointer to a queue is passed as an argument to the function which first proceeds to check for potential failures. The following situations result in failure: The queue passed is NULL, the head of the queue passed is not NULL, the tail of the queue is not NULL, and the length of the queue is not NULL. The purpose of the checks is to avoid destroying a queue that has not been properly cleared first. If none of these failures are reached, then we simply free the queue from memory, and return success.

For `queue_enqueue()`, a node is malloced and added to the queue, which is passed as a pointer to the function along with a void * pointer to the data to enqueue. If the queue pointer passed is NULL, or the malloc returns a NULL pointer for the node, the function returns a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. 

`queue_dequeue()` removes a node from the queue. A `queue_t` is passed along with void double pointer to the data parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the value of the double pointer to point to the data in the queue's head node. Then, if we fail to remove the node from the queue by the queue_delete() function call, we return a failure. If we succeed to remove the node from the queue, then we return a success.

For `queue_delete()`, a `queue_t` and void pointer to data are passed as parameters into the function. We first initialized two node pointers, a current node we intend to use, and a temporary node that may also be needed. If the queue or queue's head is NULL, we return a failure. Otherwise, we set our initialialized node pointer to point to the the queue's head so that we can start to iterate over the queue. If there are more items in the queue, and the current node's data matches the data of the node we want to delete, then we overwrite that node's properties with the next nodes properties. Once that's done, we need to free the next node, since we no longer need its allocation of memory. If the freed node happened to be the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.

For `queue_iterate()`, a `queue_t` and `queue_func_t` pointer are passed as parameters into the function. We first initialized two node pointers, a current node we intend to use, and a temporary node that may also be needed. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there's nothing to iterate over. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.

For `queue_length()`, we simply pass a `queue_t` as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0. Otherwise we simply return `queue->length`.

Finally, we completed the Makefile of our libuthread to successfully generate a library archive (.a) file, and built a test-queue.c that allows us to test our queue implementations in order.

### Phase 2 - Thread API ###
We needed to implement most of the thread management in this phase of the program, which was done by making modifications in `uthread.c` file. We predefined 4 global pointers to the 4 queues (ready, run, wait, done) to represent the states of a thread during its lifetime. We also define the state of each thread using a typdef in order to save the thread for descheduling and later scheduling. We also clearly defined the thread control block (TCB) of a typical thread, whose structure can be seen in the design choices above. Lastly, we defined the functions `uthread_start()`, `uthread_create()`, `uthread_yield()`, `uthread_exit()`, `uthread_current()`, `uthread_block()`, and `uthread_unblock()`. We also defined two custom functions for convenience, `uthread_enqueue()` and `uthread_init()`.

The custom function `uthread_enqueue()` was defined for convenience of coding. Instead of just updating the state we pass a pointer to the thread control block (TCB) and the current state of the thread as parameters of the program. By setting the current state of the TCB to equal the state we passed in to the function, we could implement a switch statement to determine which queue to place our thread in.

For `uthread_yield()`, we declare TCB pointers (next, run, done), each of which represent the state of the thread we'll be dealing with in the function. The first function call is to `preempt_save()` to save the signal state and disable interrupts. If we can't remove the next thread from the ready state queue, then we remove the running thread from the run state queue, change state, then add the running thread to the ready state queue and add the next thread to the running state queue. Then we must do a thread context switch for threads that are running and ready, by suspending execution of a currently running thread and resuming execution of another thread. This is needed whenever we deal with multiple threads. From here, while there are finished threads that exist on the done state queue, we destroy their respective stacks and free all of their thread contexts, signal set object, and memory space, simply because we don't need them anymore. Lastly, we call `preempt_restore()` to restore the signal state and reenable interrupts.

`uthread_init()` is a custom function for ease of re-use. Both `uthread_create()` and `uthread_start()` make use of it. We pass a thread function and argument of that function as parameters to the function. We must allocate the right amount of memory for the TCB, as well as allocate thread context and signal set object. Then we assign the TCB's function pointer and argument pointer to the parameters we passed in, and set the TCB's current state to ready.

For `uthread_create()`, we make a function call to `uthread_init()` defined earlier to initialize the thread we intend to create. That comes with allocating memory for a stack and pointer to the top of the stack. Once we create our thread, we add it to the ready state queue.

For `uthread_exit()`, we declare TCB pointers (me, next), each of which represent the state of the thread we'll be dealing with in the function. The first function call is to `preempt_save()` to save the signal state and disable interrupts. We remove the running thread from the run state queue and remove the next thread from the ready state queue. Then we can change state and add the running and next threads to the done state queue and running state queue, respectively. Then we make the necessary thread context switch. There is no need to restore signal state and re-enable interrupts since we're exiting the thread life cycle.

For `uthread_block()`, we declare TCB pointers (next, run), each of which represent the state of the thread we'll be dealing with in the function. The first function call is to `preempt_save()` to save the signal state and disable interrupts, since it's a critical section. We perform similar actions in this function as we do in `uthread_exit()`. We remove the running thread from the run state queue and remove the next queue from the ready state queue. Then we change state and add the running and next threads from the WAITING state queue and running state queue, respectively. We add the running thread to the waiting state queue so that the thread can next transition to the running state queue. Then we make the necessary thread context switch.  Lastly, we call `preempt_restore()` to restore the signal state and reenable interrupts.

For `uthread_unblock()`, we pass a thread as a parameter to the function. The first function call is to `preempt_save()` to save the signal state and disable interrupts, since it's a critical section. We remove the blocked thread from the waiting state queue by calling `queue_delete()`, and then add that same thread onto the ready state queue. We then call `preempt_restore()` to restore the signal state and reenable interrupts.

For `uthread_current()`, we initialize a local thread structure (current). We then dequeue the currently running thread to update the current pointer, and then re-enqueue the running thread. This strategy only works if it is guaranteed that only one thread is in the running queue at a time.

For `uthread_start()`, we pass a thread start function and the argument of that function as parameters to the function. We must iterate through each of the 4 thread states (ready, run, wait, done), in order to see where to initialize our thread. Once we set the state of our thread and add it to the running state queue, we start the timer (*Phase 4*) and create the thread that we must add to the next queue, the ready state queue.  If a thread already exists, we can simply switch to the next thread by calling uthread_yield(). Lastly, we must conduct memory cleanup in order to assure no memory leak once we no longer need a thread.

Test 1 and 2 confirmed that our function definitions were implemented properly and effectively.


### Phase 3 - Provide a thread synchronization API, namely semaphores ###
In this phase we needed to implement semaphores, which would allow the user(s) to control access to the common resources of multiple threads. 

First we needed to properly define a semaphore structure, which contains the `size_t` "count", the number of threads able to share a common resource at the same time, and waiting queue of threads waiting to use that resource. We defined the functions `sem_create()`, `sem_destroy()`, `sem_down()`, and `sem_up()`.

For `sem_create()`, we passed the count as the parameter of the function. We must first allocate memory for our semaphore structure, and create the wait queue with `queue_create()`, and initializing the count of the semaphore we just created.

For `sem_destroy()`, we passed the semaphore structure as the parameter of the function. If we fail to destory the waiting state queue associated with the semaphore, we return a failure. If we succeed to destroy the waiting state queue, then we free its memory and return a success.

For `sem_down()`, threads can ask to grab a resource, so we passed a pointer to a semaphore is passed as the parameter of the function. If the thread tries to grab a resource when the count is down to 0, it adds that thread to the semaphore's waiting queue. The thread is also put into a blocked state with `uthread_block()` and the context is switched to the next ready thread.

For `sem_up()`, threads can release a resource, so we passed a pointer to a semaphore is passed as the parameter of the function. If the thread releases a semaphore which count is 0, it needs to check whether threads exist on the waiting state queue. If so, the first thread of the waiting state queue can be unblocked with `uthread_unblock()` and placed into the ready queue for running.

Test 3, 4, and 5 confirmed that our function definitions were implemented properly and effectively.


### Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler ###

See the above *Design Choices* section.

## Building / Running ##
This program was compiled using the Linux gcc 6.3.1 compiler.

To build, clone this repository and then cd to the folder in a terminal.

Then type `make` and let the `Makefile` and `libuthread/Makefile` do the rest.

After building, tests 1 through 5 can be run by typing `./testX`
where X represents the test number.

# References #
1. Operating Systems Principles and Practice (Chapter 4).
2. Man page for sigsetops

