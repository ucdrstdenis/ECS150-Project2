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
/*                  UThread #DEFINES                    */
/* **************************************************** */
#define FAIL        -1                                  /* Fail code                                */
#define SUCCESS      0                                  /* Success code                             */

/* **************************************************** */
/*                   UThread GLOBALS                    */
/* **************************************************** */
queue_t ReadyQ;                                  		/* Global pointer to Ready Queue            */
queue_t RunQ;                                    		/* Global pointer to Running Queue          */
queue_t WaitQ;                                  		/* Global pointer to Wait Queue             */
queue_t DoneQ;                                   		/* Global pointer to Done Queue             */

/* **************************************************** */
/*                  UThread Structures                  */
/* **************************************************** */
typedef enum  {
    READY    = 0x00,                                    /* Ready list, Regs in TCB                  */
    RUNNING  = 0x01,                                    /* Running list, Regs in Proc               */
    BLOCKED  = 0x02,                                    /* Sync Vars WL, Regs in TCB                */
    FINISHED = 0x03                                     /* Finished list, Regs deleted              */
} uthread_state_t;

struct uthread_tcb {
    struct uthread_tcb *tcb;                            /* Pointer to the thread's TCB              */
    uthread_state_t state;                              /* Holds the thread's state                 */
    uthread_func_t func;                                /* Pointer to thread function               */
    uthread_ctx_t *uctx;                                /* User level thread context                */
    int exitCode;                                       /* Thread exit code                         */
    void *arg;                                          /* Pointer to thread function arg           */
    void *stack;                                        /* Pointer to top_of_stack                  */
};

typedef struct uthread_tcb utcb;                        /* Typedef for convenience                  */
/* **************************************************** */
/* **************************************************** */
/*                    UThread Yield                     */
/* **************************************************** */
void uthread_yield(void)                                /* See Fig 4.14 in Anderson Textbook        */
{
    utcb *nextTCB, *runTCB, *doneTCB;                   /* Declare TCB pointers                     */

    //disableInterrupts();                              /* TODO not sure how to do this yet         */

    if(!queue_dequeue(ReadyQ, (void **)&nextTCB)) {     /* Get the next TCB from the Ready queue    */
        runTCB = uthread_current();                     /* Get currently running thread             */
        if (runTCB == NULL) return;                     /* TODO what happens if nothing running     */
        runTCB->state = READY;                          /* Change the state of running TCB          */
        queue_dequeue(RunQ, (void**) &runTCB);          /* Remove thread from the running queue     */
        queue_enqueue(ReadyQ, (void*) runTCB);          /* Add running thread to the ready queue    */
        uthread_ctx_switch(runTCB->uctx, nextTCB->uctx);/* Switch context of runTCB and nextTCB     */
        queue_enqueue(RunQ, (void*) nextTCB);           /* Add the next thread to the running queue */
        nextTCB->state = RUNNING;                       /* Change the state of the next TCB         */
    }

    while(!queue_dequeue(DoneQ,(void**)&doneTCB)) { /* While threads to deQ exist on DoneQ  */
        uthread_ctx_destroy_stack(doneTCB->stack);      /* Destroy their stacks                     */
        free(doneTCB->uctx);                            /* Free user-level thread contexts          */
        free(doneTCB);                                  /* Free TCBs from memory                    */
    }

    // enableInterrupts();                              /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                Static UThread Init                   */
/* **************************************************** */
static utcb *uthread_init(uthread_func_t func, void *arg)
{
    struct uthread_tcb *tcb = malloc(sizeof(utcb));     /* Alloc thread control block structure     */
    tcb->uctx    = malloc(sizeof(uthread_ctx_t));       /* Alloc user-level thread context struct   */
    tcb->tcb     = tcb;                                 /* Set the TCB pointer to itself            */
    tcb->func    = func;                                /* Set the TCB function pointer             */
    tcb->arg     = arg;                                 /* Set the TCB function argument pointer    */
    tcb->state   = READY;                               /* Set the TCB state                        */
    return tcb;									        /* Return pointer to the TCB 				*/
}
/* **************************************************** */
/* **************************************************** */
/*                   UThread Create                     */
/* **************************************************** */
int uthread_create(uthread_func_t func, void *arg)
{
    struct uthread_tcb *tcb = uthread_init(func, arg);  /* Alloc/Init thread control block struct   */
    tcb->stack   = uthread_ctx_alloc_stack();           /* Alloc stack, Set pointer to stack top    */
    //tcb->state   = READY;                             /* Set the TCB state                        */
    queue_enqueue(ReadyQ, (void*) tcb);                 /* Add the thread to the ready queue        */

    /* Initialize user-level thread context */
    if (uthread_ctx_init(tcb->uctx, tcb->stack, func, arg))
        return FAIL;

    return SUCCESS;                                     /* Return success                           */
}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Exit                      */
/* **************************************************** */
void uthread_exit(void)
{
    utcb *me, *next;                                    /* Declare TCB pointers                     */

    me = uthread_current();                             /* Get currently running thread             */
    queue_dequeue(RunQ, (void **) &me);                 /* Remove thread from the running queue     */
    me->state = FINISHED;                               /* Set the state                            */
    queue_enqueue(DoneQ, (void*) me);                   /* Add the thread to the finished queue     */

    queue_dequeue(ReadyQ, (void**) &next);              /* Get the next TCB from the ready queue    */
    next->state = RUNNING;                              /* Update the next TCB's state              */
    queue_enqueue(RunQ, (void*) next);                  /* Add the next TCB to the running queue    */

    uthread_ctx_switch(me->uctx, next->uctx);           /* Switch context of threads                */

    while(!queue_dequeue(DoneQ, (void**) &me)) {        /* While threads to deQ exist on DoneQ  	*/
        uthread_ctx_destroy_stack(me->stack);           /* Destroy the stack                        */
        free(me->uctx);                                 /* Free user-level thread context           */
        free(me);                                       /* Free TCB from memory                     */
    }

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
    
    //TODO don't use queue_dequeue / queue_enqueue here */
	struct uthread_tcb *current;
    queue_dequeue(RunQ, (void**) &current);       	    /* Get the next TCB from the ready queue           */
    queue_enqueue(RunQ, (void*) current);

    return current;         							/* Return pointer to currently running TCB         */
}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Start                     */
/* **************************************************** */
void uthread_start(uthread_func_t start, void *arg)
{
	unsigned int i;
	queue_t QArray[] = {ReadyQ, RunQ, WaitQ, DoneQ};	/* Declare array of queue pointers 				   	*/

	/* Create the global queues */
	for (i = 0; i < 4; i++)			     				/* For each item in QArray[] 					  	*/
		QArray[i] = queue_create();						/* Alloc/Init global pointer for each queue        	*/

	utcb *startThread = uthread_init(start, arg);		/* Alloc/Init a TCB to the start thread 		   	*/
    // while() {

    // uthread_create(start, arg);                     /* Create and initialize a new thread              	*/

	/* TODO Phase 2 */

    //  }

    /* Destroy the queues */
    for (i = 0; i < 4; i++)
    	queue_destroy(QArray[i]);						/* Destroy each queue in QArray[] 					*/
}
/* **************************************************** */
