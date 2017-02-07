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
queue_t ReadyQ;                                         /* Global pointer to Ready Queue            */
queue_t RunQ;                                           /* Global pointer to Running Queue          */
queue_t WaitQ;                                          /* Global pointer to Wait Queue             */
queue_t DoneQ;                                          /* Global pointer to Done Queue             */
/* **************************************************** */
/*                  UThread Structures                  */
/* **************************************************** */
typedef enum  {
    READY   = 0x00,                                     /* Ready list, Regs in TCB                  */
    RUNNING = 0x01,                                     /* Running list, Regs in Proc               */
    BLOCKED = 0x02,                                     /* Sync Vars WL, Regs in TCB                */
    DONE    = 0x03                                      /* Finished list, Regs deleted              */
} uthread_state_t;

struct uthread_tcb {
    struct uthread_tcb *tcb;                            /* Pointer to the thread's TCB              */
    uthread_state_t state;                              /* Holds the thread's state                 */
    uthread_func_t func;                                /* Pointer to thread function               */
    uthread_ctx_t *uctx;                                /* User level thread context                */
    int exitCode;                                       /* Thread exit code                         */
    void *arg;                                          /* Pointer to thread function arg           */
    void *stack;                                        /* Pointer to the top of the stack          */
};

typedef struct uthread_tcb utcb;                        /* Typedef for convenience                  */
typedef uthread_state_t ustate;                         /* Typedef for convenience                  */
/* **************************************************** */
/* **************************************************** */
/*              Static UThread Enqueue                  */
/* **************************************************** */
static int uthread_enqueue(utcb *tcb, ustate state){
    tcb->state = state;                                 /* Set the state                            */
    switch(state) {                                     /* Choose queue to add the thread to        */
        case READY:                                     /* Add to ready queue                       */
            return queue_enqueue(ReadyQ, (void *) tcb);
        case RUNNING:                                   /* Add to running queue                     */
            return queue_enqueue(RunQ,   (void *) tcb);
        case BLOCKED:                                   /* Add to waiting queue                     */
            return queue_enqueue(WaitQ,  (void *) tcb);
        case DONE:                                      /* Add to done queue                        */
            return queue_enqueue(DoneQ,  (void *) tcb);
    }
    return FAIL;                                        /* Passed invalid state, return FAIL        */
}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Yield                     */
/* **************************************************** */
void uthread_yield(void)                                /* See Fig 4.14 in Anderson Textbook        */
{
    utcb *nextTCB, *runTCB, *doneTCB;                   /* Declare TCB pointers                     */

    //disableInterrupts();                              /* TODO not sure how to do this yet         */
    if(!queue_dequeue(ReadyQ, (void **) &nextTCB)) {    /* Get the next TCB from the Ready queue    */
        queue_dequeue(RunQ,   (void **) &runTCB);       /* Remove thread from the running queue     */
        if (runTCB == NULL) return;                     /* TODO what happens if nothing running?    */
        uthread_enqueue(runTCB, READY);                 /* Change state, add to ready queue         */
        uthread_enqueue(nextTCB, RUNNING);              /* Change state, add to running queue       */
        uthread_ctx_switch(runTCB->uctx, nextTCB->uctx);/* Switch context of runTCB and nextTCB     */
    }

    while(!queue_dequeue(DoneQ,(void **) &doneTCB)) {   /* While threads to deQ exist in DoneQ      */
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
    return tcb;                                         /* Return pointer to the TCB                */
}
/* **************************************************** */
/* **************************************************** */
/*                   UThread Create                     */
/* **************************************************** */
int uthread_create(uthread_func_t func, void *arg)
{
    struct uthread_tcb *tcb = uthread_init(func, arg);  /* Alloc/Init thread control block          */
    tcb->stack = uthread_ctx_alloc_stack();             /* Alloc stack, Set pointer to stack top    */
    uthread_enqueue(tcb, READY);                        /* Add the thread to the ready queue        */

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
    uthread_enqueue(me, DONE);                          /* Set the state, add to done queue         */
    queue_dequeue(ReadyQ, (void **) &next);             /* Get the next TCB from the ready queue    */
    uthread_enqueue(next, RUNNING);                     /* Set the state, add to running queue      */
    uthread_ctx_switch(me->uctx, next->uctx);           /* Switch context of threads                */
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
    //TODO don't use queue_dequeue / queue_enqueue here
    struct uthread_tcb *current;
    queue_dequeue(RunQ, (void **) &current);            /* Get the next TCB from the ready queue           */
    queue_enqueue(RunQ, (void *) current);
    return current;                                     /* Return pointer to currently running TCB         */
}
/* **************************************************** */
/* **************************************************** */
/*                    UThread Start                     */
/* **************************************************** */
void uthread_start(uthread_func_t start, void *arg)
{
    unsigned int i;
    utcb *idleThread;
    queue_t *QArray[]={&ReadyQ, &RunQ, &WaitQ, &DoneQ}; /* Declare array of queue pointers                  */

    /* Create the global queues */
    for (i = 0; i < 4; i++)                             /* For each queue in QArray[]                       */
        *QArray[i] = queue_create();                    /* Alloc/Init global pointer to each queue          */

    /* Create idle and 1st threads */
    idleThread = uthread_init(NULL, NULL);              /* Alloc/Init a TCB to the idle thread              */
    uthread_enqueue(idleThread, RUNNING);               /* Set the state, add to running queue              */
    uthread_create(start, arg);                         /* Create 1 thread, auto-add to ready queue         */

    /* Main loop */
     while(queue_length(ReadyQ))    uthread_yield();    /* While ready threads exist, switch to next thread */

    /* Destroy the queues */
    queue_delete(RunQ, (void *) idleThread);            /* Remove the idleThread from the Running queue     */
    for (i = 0; i < 4; i++)                             /* For each queue in QArray[]                       */
        queue_destroy(*QArray[i]);                      /* Destroy the queue                                */
}
/* **************************************************** */
