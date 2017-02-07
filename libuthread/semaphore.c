#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#define _UTHREAD_PRIVATE
#include "preempt.h"
#include "queue.h"
#include "semaphore.h"                                  /* sem_t is a pointer to a semaphore */
#include "uthread.h"
#include <stdio.h>                                      /* For printf. Remove when done debugging */

/* **************************************************** */
/*                 Semaphore #DEFINES                   */
/* **************************************************** */
#define FAIL        -1                                  /* Fail code                            */
#define SUCCESS      0                                  /* Success code                         */

/* **************************************************** */
/*                 Semaphore Structures                 */
/* **************************************************** */
typedef struct semaphore {
    size_t count;                                       /* Semaphore count long unsigned int    */
    queue_t waitQ;                                      /* Queue of threads waiting for sem     */
} semaphore;
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Create                   */
/* **************************************************** */
sem_t sem_create(size_t count)
{
    sem_t sem = (semaphore*) malloc(sizeof(semaphore)); /* Allocate memory for the semaphore    */
    sem->waitQ = queue_create();                        /* Queue of waiting threads             */
    sem->count = count;                                 /* Semaphore Count                      */
    printf("DEBUG: sem_create. passed_count=%lu, sem->count=%lu\n", count, sem->count);
    return sem;                                         /* Return the semaphore                 */
}
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Destroy                  */
/* **************************************************** */
int sem_destroy(sem_t sem)
{
    if(queue_destroy(sem->waitQ)) return FAIL;          /* Queue destroy failed, return FAIL    */
	free(sem);                                          /* Deallocate the memory                */
    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Semaphore Down                    */
/* **************************************************** */
int sem_down(sem_t sem)
{
    struct uthread_tcb *thread;
    sem->count--;
    printf("DEBUG: sem_down. count=%lu\n", sem->count);
    if(sem->count < 0) {                                /* Decrement count, check if < 0        */
        printf("DEBUG: sem_down. Blocking thread\n");
        queue_enqueue(sem->waitQ, (void *) thread);     /* Add thread to the semaphore's queue  */
	    uthread_block();                                /* Block the thread                     */
	}
    return SUCCESS;                                     /* Return SUCCESS                       */
}
/* **************************************************** */
/* **************************************************** */
/*                     Semaphore Up                     */
/* **************************************************** */
int sem_up(sem_t sem)
{
    struct uthread_tcb *thread;
	sem->count++;
    printf("DEBUG: sem_up. count=%lu\n", sem->count);
    if(sem->count > 0) {                                /* If incremented count > 0            */
        printf("DEBUG: sem_up()\n");
	    if(!queue_dequeue(sem->waitQ, (void**) &thread)) {/* If items to dequeue exist           */
	        printf("DEBUG: sem_up. unblocking thread\n");
	        uthread_unblock(thread);                    /* Unblock the first item in the queue */
	    }
	}
    return SUCCESS;
}
/* **************************************************** */
