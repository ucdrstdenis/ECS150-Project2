/*
 * Keeps thread in loop that goes forever 
 * Purpose was to check preempt debug output
 * Doesn't do anything once debug statements removed
*/

#include <stdio.h>
#include <stdlib.h>

#include <uthread.h>

void hello(void* arg)
{
	//printf("Hello world!\n");
	while(1);/* Run forever, should see interrupts hitting */

}

int main(void)
{
	uthread_start(hello, NULL);
	return 0;
}
