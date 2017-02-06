#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#define _UTHREAD_PRIVATE
#include "preempt.h"
#include "queue.h"
#include "semaphore.h"                                  /* sem_t is a pointer to a semaphore */
#include "uthread.h"

#define FAIL        -1                                  /* Fail code                                */
#define SUCCESS      0                                  /* Success code                             */

/* **************************************************** */
/*                 Semaphore Structures                 */
/* **************************************************** */
typedef struct semaphore {

	/* TODO Phase 3 */

} semaphore;
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Create                   */
/* **************************************************** */
sem_t sem_create(size_t count)
{
    sem_t sem = (semaphore*) malloc(sizeof(semaphore));

	/* TODO Phase 3 */

    return sem;
}
/* **************************************************** */
/* **************************************************** */
/*                   Semaphore Destroy                  */
/* **************************************************** */
int sem_destroy(sem_t sem)
{
	/* TODO Phase 3 */

    return SUCCESS;
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
