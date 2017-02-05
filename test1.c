/*
 * Simple hello world test
 *
 * Tests the creation of a single thread and its successful return.
 */

#include <stdio.h>
#include <stdlib.h>

#include <uthread.h>
#include "uthread.h"			//TODO, remove soft link in directory AND
//GET #include <uthread.h> to work

void hello(void* arg)
{
	printf("Hello world!\n");
}

int main(void)
{
	uthread_start(hello, NULL);
	return 0;
}
