#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#define _UTHREAD_PRIVATE
#include "preempt.h"
#include "queue.h"
#include "semaphore.h"                                  /* sem_t is a pointer to a semaphore */
#include "uthread.h"

/* **************************************************** */
/*                 Semaphore #DEFINES                   */
/* **************************************************** */
#define FAIL        -1                                  /* Fail code                            */
#define SUCCESS      0                                  /* Success code                         */

/* **************************************************** */
/*                 Semaphore Structures                 */
/* **************************************************** */
typedef struct semaphore {
    size_t count;                                       /* Semaphore count                      */
    queue_t WaitQ;                                      /* Queue of threads waiting for sem     */
} semaphore;
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Create                   */
/* **************************************************** */
sem_t sem_create(size_t count)
{
    sem_t sem = (semaphore*) malloc(sizeof(semaphore));
    sem->count = count;                                 /* Semaphore Count                      */
    sem->WaitQ = queue_create();                        /* Queue of waiting threads             */
    return sem;
}
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Destroy                  */
/* **************************************************** */
int sem_destroy(sem_t sem)
{
    if(queue_destroy(sem->WaitQ)) return FAIL;          /* Queue destroy failed, return FAIL    */
	free(sem);                                          /* Deallocate the memory                */
    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Semaphore Down                    */
/* **************************************************** */
int sem_down(sem_t sem)
{
	/* TODO Phase 3 */

    return SUCCESS;
}
/* **************************************************** */
/* **************************************************** */
/*                     Semaphore Up                     */
/* **************************************************** */
int sem_up(sem_t sem)
{
	/* TODO Phase 3 */

    return SUCCESS;
}
/* **************************************************** */
