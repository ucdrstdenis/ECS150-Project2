% ECS 150: Project #2 - User-level thread library

# General information
We approached each phase individually, from the beginning stages of phase 1, to the final stages of phase 4.

## Phase 1 - Creating new execution threads.
We first implemented a FIFO queue, by making modifications in queue.c. We defined the node and queue structures, then defined the functions queue_create, queue_destroy, queue_enqueue, queue_dequeue, queue_delete, queue_iterate, and queue_length. Our implementations all had to be in O(1) constant time, so we chose to use if statements and while loops and NOT for loops.

For queue_create, we first allocated memory space for a queue we locally initialize. If we failed to allocate proper memory space for our initialization, we would return NULL for the function call. If we succeded to allocate proper memory space for our initialization, then we set the queue head to NULL, tail to NULL, and length to 0. Then we return the initialized queue.

For queue_destroy, we pass a queue structure as a parameter into our function. If the queue is NULL, we return a failure. If the head of the queue is not NULL, we return a failure. If the tail of the queue is not NULL, we return a failure. If the length of the queue is not NULL, we return a failure. Essentially we don't want to destroy a queue that is not empty. If none of these failures are reached, then we simply free the queue, and return a success.

For queue_enqueue, we need to push a node onto the queue. We pass a queue structure and data pointer as parameters into our function. We first allocated memory space for a node we locally initialize. If we failed to allocate proper memory space for our initialization, we would return a failure. If the queue we passed in as a parameter was NULL, we would also return a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. 

For queue_dequeue, we need to remove a node from the queue. We pass a queue structure and data double pointer as parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the data double pointer we passed in to equal to the data of the queue's head, by deferencing. Then, if we fail to remove the node from the queue by the queue_delete() function call, then we return a failure. If we succeed to remove the node from the queue, then we return a success.

For queue_delete, we pass a queue structure and data pointer as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the queue or queue's head is NULL, we return a failure. Else, we set our initialized current node to equal the queue's head, so we can start to iterate over the queue. If there are more items in the queue, and the current node's data is the data of the node we want to delete, then we set the temporary node as the next node after the current node, so that we can overrite by setting the data and next values of the current node to equal the data and next values of the following (temporary node). Once that's done, we need to free the temporary node to be safe, since we no longer need its allocation of memory. If the node we overrited (deleted) was the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.

For queue_iterate, we pass a queue structure and queue function as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there exists a queue. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.

For queue_length, we simply pass a queue structure as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0.

Lastly, we completed the makefile of our libuthread so we can successfully generate a library archive, and we had to add other C files as we started implementing them from one phase to the next phase. We also built a test-queue.c that allows us to test our queue implementations in order.


## Phase 2 - Schedule the execution of threads in a round-robin fashion
We needed to implement most of the thread management in this phase of the program, which was done by making modifications in uthread.c file. We predefined 4 global pointers to the 4 queues (ready, run, wait, done) to represent the states of a thread during its lifetime. We also defined the set of registers for each state in order to save the thread for descheduling and later scheduling. We also clearly defined the thread control block (TCB) of a typical thread, including in its structure: the thread's state, a pointer to the thread function, a user-level thread context (for context switching), a signal set (for phase 4), and two pointers, one to the thread function's argument and one to the top of the thread function's stack. Lastly, we defined the functions uthread_enqueue, uthread_yield, uthread_init, uthread_create, uthread_exit, uthread_block, uthread_unblock, uthread_current, and uthread_start.

For uthread_enqueue, we pass a pointer to the thread control block (TCB) and the current state of the thread as parameters of the program. By setting the current state of the TCB to equal the state we passed in to the function, we could implement a switch statement to determine which thread state queue to place our TCB in.

For uthread_yield, we declare TCB pointers (next, run, done), each of which represent the state of the thread we'll be dealing with in the function. We also save the signal state and disable interrupts (*Phase 4*). If we can't remove the next thread from the ready state queue, then we remove the running thread from the run state queue, change state, then add the running thread to the ready state queue and add the next thread to the running state queue. Then we must do a thread context switch for threads that are running and ready, by suspending execution of a currently running thread and resuming execution of another thread. This is needed whenever we deal with multiple threads. From here, while there are finished threads that exist on the done state queue, we destroy their respective stacks and free all of their thread contexts, signal sets, and memory space, simply because we don't need them anymore. Lastly, we restore the signal states and re-enable the interrupts (*Phase 4*). 




If we don't successfully execute queue_dequeue of removing the TCB of the run state from the ready state queue, then we do the following: remove the thread (run TCB) from the running queue, then change state and add the removed thread (run TCB) to the ready state queue and TCB of the next state to the running queue, and switch thread context of the run and next TCB. This allows us to successfully transition from running to ready state, which is ultimately what yield is supposed to do. Then we test to see  




## Phase 3 - Provide a thread synchronization API, namely semaphores
## Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler



