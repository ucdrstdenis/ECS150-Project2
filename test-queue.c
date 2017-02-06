#include <stdio.h>
#include <queue.h>
#include <assert.h>

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
	queue_enqueue(myqueue, &a);
	queue_enqueue(myqueue, &b);
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
