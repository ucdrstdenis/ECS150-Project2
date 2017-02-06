#include <stdio.h>
#include <queue.h>
#include <assert.h>


/* A few tests can be to create queues, enqueue some items, make sure that these items are dequeued in the same order, delete some items, test the length of the queue, etc.
*/

/* Below is directly off Piazza */
queue_t myqueue;

void mycustomfunc(void *data)
{
	int *x = (int*)data;
	if (*x == 2)
		queue_delete(myqueue, x);
}

void f()
{
	int a = 2;
	int b = 3;
	
	myqueue = queue_create();
	queue_enqueue(myqueue, (void*) &a);
	queue_enqueue(myqueue, (void*) &b);
	assert(queue_length(myqueue) == 2);

        queue_iterate(myqueue, mycustomfunc);

	// after iterating, one element has been removed
	assert(queue_length(myqueue) == 1);

	assert(queue_destroy(NULL) == -1);
	assert(queue_enqueue(NULL, NULL) == -1);
}




int main (void)
{
    f();
    return 0;
}
