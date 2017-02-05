#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define _UTHREAD_PRIVATE
#include "context.h"
#include "preempt.h"
#include "queue.h"
#include "uthread.h"


/* **************************************************** */
/*                     UThread TCB                      */
/* **************************************************** */
struct uthread_tcb {

	/* TODO Phase 2 */

};

typedef struct uthread_tcb utcb;
/* **************************************************** */
/* **************************************************** */
/*                     UThread Yield                    */
/* **************************************************** */
void uthread_yield(void)
{

	/* TODO Phase 2 */

}
/* **************************************************** */
/* **************************************************** */
/*                     UThread Create                   */
/* **************************************************** */
int uthread_create(uthread_func_t func, void *arg)
{

	/* TODO Phase 2 */

    return 0;                                           /* Return success                       */

}
/* **************************************************** */
/* **************************************************** */
/*                      UThread Exit                    */
/* **************************************************** */
void uthread_exit(void)
{

	/* TODO Phase 2 */

}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Block                     */
/* **************************************************** */
void uthread_block(void)
{

	/* TODO Phase 2 */

}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Unblock                   */
/* **************************************************** */
void uthread_unblock(struct uthread_tcb *uthread)
{

	/* TODO Phase 2 */

}
/* **************************************************** */
/* **************************************************** */
/*                  UThread Current                     */
/* **************************************************** */
struct uthread_tcb *uthread_current(void)
{

    struct uthread_tcb *uthread = malloc(sizeof(utcb));

	/* TODO Phase 2 */

    return uthread;

}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Start                     */
/* **************************************************** */
void uthread_start(uthread_func_t start, void *arg)
{

	/* TODO Phase 2 */

}
/* **************************************************** */
