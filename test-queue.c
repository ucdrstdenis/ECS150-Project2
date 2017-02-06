#include <queue.h>

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
	queue_enqueue(a);
	queue_enqueue(b);
	assert(queue_lenght(myqueue) == 2);

        queue_iterate(myqueue, mycustomfunc);

	// after iterating, one element has been removed
	assert(queue_lenght(myqueue) == 1);
}


int main (void)
{
    f();
    return 0;
}
