% ECS 150: Project #2 - User-level thread library

# General information
We approached each phase individually, from the beginning stages of phase 1, to the final stages of phase 4.

## Phase 1 - Creating new execution threads.
We first implemented a FIFO queue, by making modifications in queue.c. We defined the node and queue structures, then defined the functions queue_create, queue_destroy, queue_enqueue, queue_dequeue, queue_delete, queue_iterate, and queue_length.

For queue_create, we first allocated memory space for a queue we locally initialize. If we failed to allocate proper memory space for our initialization, we would return NULL for the function call. If we succeded to allocate proper memory space for our initialization, then we set the queue head to NULL, tail to NULL, and length to 0. Then we return the initialized queue.

For queue_destroy, we pass a queue structure as a parameter into our function. If the queue is NULL, we return a failure. If the head of the queue is not NULL, we return a failure. If the tail of the queue is not NULL, we return a failure. If the length of the queue is not NULL, we return a failure. Essentially we don't want to destroy a queue that is not empty. If none of these failures are reached, then we simply free the queue, and return a success.

For queue_enqueue, we need to push a node onto the queue. We pass a queue structure and data pointer as parameters into our function. We first allocated memory space for a node we locally initialize. If we failed to allocate proper memory space for our initialization, we would return a failure. If the queue we passed in as a parameter was NULL, we would also return a failure. If a queue is not empty, but the head of the queue is NULL, we set the head of the queue to be our locally initialized node. If the head of the queue is not NULL, then we set the tail of the queue to be our locally initialized node, by simply pointing the current tail to the node. We make the final adjustments by initializing our node's data, attaching our node to the head of the queue, pointing the queue's tail to our node, and increasing the length of our queue. 

For queue_dequeue, we need to remove a node from the queue. We pass a queue structure and data double pointer as parameters into our function. If the queue is NULL, queue's head is NULL, or the queue's tail is NULL, we return a failure. If not, then we set the data double pointer we passed in to equal to the data of the queue's head, by deferencing. Then, if we fail to remove the node from the queue by the queue_delete() function call, then we return a failure. If we succeed to remove the node from the queue, then we return a success.

For queue_delete, we pass a queue structure and data pointer as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the queue or queue's head is NULL, we return a failure. Else, we set our initialized current node to equal the queue's head, so we can start to iterate over the queue. If there are more items in the queue, and the current node's data is the data of the node we want to delete, then we set the temporary node as the next node after the current node, so that we can overrite by setting the data and next values of the current node to equal the data and next values of the following (temporary node). Once that's done, we need to free the temporary node to be safe, since we no longer need its allocation of memory. If the node we overrited (deleted) was the tail of the queue, we set the current node as our new queue's tail, and decrement the length of the queue, since one node has been deleted from there. Then we can return a success. However, if the current node's data is not the data of the node we want to delete, we simply iterate through the queue until we find the node we need to delete. If the node we need to delete happens to be the queue's tail, we must check the following: if the the tail is the head, there's only one item in the queue, so we can just nullify the entire queue (basically emptying it). If the tail isn't the head, we use our temporary node we initialized in the beginning to be our new tail. We decrement the length of the queue, since one node has been deleted from there, and finally return a success.

For queue_iterate, we pass a queue structure and queue function as parameters into our function. We first initialized two node pointers, a current node we intend to use, and a temporary node we'll also need. If the function or queue is NULL, then we return a failure, because there's nothing to iterate over. If the queue's head is NULL, there is also nothing to iterate, but we return a success since there exists a queue. We set our initialized current node to equal the queue's head, so we can start to iterate over the queue. As we iterate through the queue, we set the temporary node as the next node after the current node. Then we call the function "func" for the current node in the queue. If the function call was successful, we can continue to iterate through the queue. Once we reach the queue's tail, we perform one last function call to the node. The queue_iterate function essentially allows us to execute function "func" calls against every node or element in the queue.

For queue_length, we simply pass a queue structure as the parameter into our function, in order to return the length of our queue. If the queue's head is NULL, we can determine that the length of the queue is 0.

Lastly, we completed the makefile of our libuthread so we can successfully generate a library archive, and we had to add other C files as we started implementing them from one phase to the next phase. We also built a test-queue.c that allows us to test our queue implementations in order.


## Phase 2 - Schedule the execution of threads in a round-robin fashion



## Phase 3 - Provide a thread synchronization API, namely semaphores
## Phase 4 - Be preemptive, that is to provide an interrupt-based scheduler



