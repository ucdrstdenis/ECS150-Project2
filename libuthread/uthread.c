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
#define ZERO         0                                  /* Success code                             */
#define BOOYA        0                                  /* Success code                             */

/* **************************************************** */
/*                  UThread GLOBALS                     */
/* **************************************************** */
static queue_t ReadyQ;                                  /* Global pointer to Ready Queue            */
static queue_t RunningQ;                                /* Global pointer to Running Queue          */
static queue_t WaitingQ;                                /* Global pointer to Waiting Queue          */
static queue_t FinishedQ;                               /* Global pointer to Finished Queue         */

/* **************************************************** */
/*                  UThread Structures                  */
/* **************************************************** */
typedef enum  {
    READY    = 0x00,                                    /* Ready list, Regs in TCB                  */
    RUNNING  = 0x01,                                    /* Running list, Regs in Proc               */
    WAITING  = 0x02,                                    /* Sync Vars WL, Regs in TCB                */
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
    void *sp;                                           /* Stack pointer                            */
    void *pc;                                           /* Thread program counter                   */
};

typedef struct uthread_tcb utcb;                        /* Typedef for convenience                  */
/* **************************************************** */
/* **************************************************** */
/*                     UThread Yield                    */
/* **************************************************** */
void uthread_yield(void)                                /* See Fig 4.14 in Anderson Textbook        */
{
    utcb *nextTCB, *runTCB, *doneTCB;                   /* Declare TCB pointers                     */

    //disableInterrupts();                              /* TODO not sure how to do this yet         */

    if(queue_dequeue(ReadyQ, &nextTCB)) {               /* Get the next TCB from the Ready queue    */
        // Nothing to run, go back to running old thread
    } else {
        runTCB = uthread_current();                     /* Get currently running thread             */
        if (runTCB == NULL) return;                     /* TODO what happens if nothing running     */
        runTCB->state = READY;                          /* Change state of running TCB              */
        queue_dequeue(RunningQ, &runTCB);               /* Remove thread from the running queue     */
        queue_enqueue(ReadyQ, runTCB);                  /* Add running thread to the ready queue    */
        uthread_ctx_switch(runTCB->uctx, nextTCB->uctx);/* Switch context of runTCB and nextTCB     */
        queue_enqueue(RunningQ, nextTCB);               /* Add the next thread to the running queue */
        nextTCB->state = RUNNING;                       /* Change the state of the next TCB         */
    }

    while(!queue_dequeue(FinishedQ, &doneTCB)) {        /* While threads to deQ exist on finishedQ  */
        uthread_ctx_destroy_stack(doneTCB->stack);      /* Destroy their stacks                     */
        free(doneTCB->uctx);                            /* Free user-level thread contexts          */
        free(doneTCB);                                  /* Free TCBs from memory                    */
    }

    // enableInterrupts();                              /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                   UThread Create                     */
/* **************************************************** */
int uthread_create(uthread_func_t func, void *arg)
{
    struct uthread_tcb *tcb = malloc(sizeof(utcb));     /* Alloc thread control block structure     */
    tcb->uctx    = malloc(sizeof(uthread_ctx_t));       /* Alloc user-level thread context struct   */
    tcb->stack   = uthread_ctx_alloc_stack();           /* Alloc stack, Set pointer to stack top    */
    tcb->tcb     = tcb;                                 /* Set the TCB pointer to itself            */
    tcb->func    = func;                                /* Set the TCB function pointer             */
    tcb->arg     = arg;                                 /* Set the TCB func argument pointer        */
    tcb->state   = READY;                               /* Set the TCB state                        */
    queue_enqueue(ReadyQ, tcb);                         /* Add the thread to the ready queue        */

    /* Initialize user-level thread context */
    if (uthread_ctx_init(tcb->uctx, tcb->stack, func, arg))
        return FAIL;

    return BOOYA;                                       /* Return success                           */
}
/* **************************************************** */
/* **************************************************** */
/*                     UThread Exit                     */
/* **************************************************** */
void uthread_exit(void)
{
    utcb *me, next;                                     /* Declare TCB pointers                     */

    me = uthread_current();                             /* Get currently running thread             */
    queue_dequeue(RunningQ, &me);                       /* Remove thread from the running queue     */
    me->state = FINISHED;                               /* Set the state                            */
    queue_enqueue(FinishedQ, me);                       /* Add the thread to the finished queue     */

    queue_dequeue(ReadyQ, &next);                       /* Get the next TCB from the ready queue    */
    next->state = RUNNING;                              /* Update the next TCB's state              */
    queue_enqueue(RunningQ, next);                      /* Add the next TCB to the running queue    */

    uthread_ctx_switch(me->uctx, next->uctx);           /* Switch context of threads                */

    while(!queue_dequeue(FinishedQ, &me)) {             /* While threads to deQ exist on finishedQ  */
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
    return (utcb*) RunningQ->head;                      /* Return pointer to currently running TCB         */
}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Start                     */
/* **************************************************** */
void uthread_start(uthread_func_t start, void *arg)
{
    ReadyQ    = queue_create();                         /* Alloc/Init global pointer to Ready queue        */
    RunningQ  = queue_create();                         /* Alloc/Init global pointer to Running queue      */
    WaitingQ  = queue_create();                         /* Alloc/Init global pointer to Waiting queue      */
    FinishedQ = queue_create();                         /* Alloc/Init global pointer to Finished queue     */

    uthread_create(start, arg);                         /* Create and initialize a new thread              */

	/* TODO Phase 2 */

    queue_destroy(FinishedQ);                           /* Destroy the global ready queue                   */
    queue_destroy(WaitingQ);                            /* Destroy the global waiting queue                 */
    queue_destroy(RunningQ);                            /* Destroy the global running queue                 */
    queue_destroy(ReadyQ);                              /* Destroy the global ready queue                   */
}
/* **************************************************** */
