#include <stdio.h>
#include <assert.h>

#include <queue.h>

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

void test_queue()
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
        printf("Test: queue_length(myqueue)\n");
	
	
	assert(queue_length(NULL) == -1);
	printf("Test: queue_length(NULL)\n");

	assert(queue_destroy(NULL) == -1);
	printf("Test: queue_destroy(NULL)\n");

	assert(queue_dequeue(NULL, NULL) == -1);
	printf("Test: queue_dequeue(NULL, NULL)\n");
	
	assert(queue_enqueue(NULL, NULL) == -1);
	printf("Test: queue_enqueue(NULL, NULL)\n");
}




int main (void)
{
    test_queue();
    return 0;
}
