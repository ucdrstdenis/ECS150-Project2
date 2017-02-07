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
/*                  uThread #DEFINES                    */
/* **************************************************** */
#define FAIL        -1                                  /* Fail code                                */
#define SUCCESS      0                                  /* Success code                             */
#define NQUEUES      4                                  /* Total number of global queues            */

/* **************************************************** */
/*                   UThread GLOBALS                    */
/* **************************************************** */
queue_t ReadyQ;                                         /* Global pointer to Ready Queue            */
queue_t RunQ;                                           /* Global pointer to Running Queue          */
queue_t WaitQ;                                          /* Global pointer to Wait Queue             */
queue_t DoneQ;                                          /* Global pointer to Done Queue             */
/* **************************************************** */
/*                  uThread Structures                  */
/* **************************************************** */
typedef enum  {                                         /* See Anderson Textbook Figure 4.10        */
    READY   = 0x00,                                     /* Ready list, Regs in TCB                  */
    RUNNING = 0x01,                                     /* Running list, Regs in Proc               */
    BLOCKED = 0x02,                                     /* Sync Vars WL, Regs in TCB                */
    DONE    = 0x03                                      /* Finished list, Regs to be deleted        */
} uthread_state_t;

struct uthread_tcb {
    uthread_state_t state;                              /* Holds the thread's state                 */
    uthread_func_t func;                                /* Pointer to thread function               */
    uthread_ctx_t *uctx;                                /* User level thread context                */
    void *arg;                                          /* Pointer to thread function arg           */
    void *stack;                                        /* Pointer to the top of the stack          */
};

typedef struct uthread_tcb utcb;                        /* Typedef for convenience                  */
typedef uthread_state_t ustate;                         /* Typedef for convenience                  */
/* **************************************************** */
/* **************************************************** */
/*                Static uThread Enqueue                */
/* **************************************************** */
static int uthread_enqueue(utcb *tcb, ustate state)
{                                                       /* Function for convenience                 */
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
/*                    uThread Yield                     */
/* **************************************************** */
void uthread_yield(void)                                /* See Fig 4.14 in Anderson Textbook        */
{
    utcb *nextTCB, *runTCB, *doneTCB;                   /* Declare TCB pointers                     */

    //disableInterrupts();                              /* TODO not sure how to do this yet         */

 /* TODO I think this should maybe check WaitQ first??? */
 /* If no items in WaitQ are ready, then check ReadyQ */

    if(!queue_dequeue(ReadyQ, (void **) &nextTCB)) {    /* Get the next TCB from the Ready queue    */
        queue_dequeue(RunQ,   (void **) &runTCB);       /* Remove thread from the running queue     */
        //if (runTCB == NULL) return;                   /* TODO what happens if nothing running?    */
        uthread_enqueue(runTCB, READY);                 /* Change state, add to ready queue         */
        uthread_enqueue(nextTCB, RUNNING);              /* Change state, add to running queue       */
        uthread_ctx_switch(runTCB->uctx, nextTCB->uctx);/* Switch context of runTCB and nextTCB     */
    }

    while(!queue_dequeue(DoneQ, (void **) &doneTCB)) {  /* While threads to deQ exist in DoneQ      */
        uthread_ctx_destroy_stack(doneTCB->stack);      /* Destroy their stacks                     */
        free(doneTCB->uctx);                            /* Free user-level thread contexts          */
        free(doneTCB);                                  /* Free TCBs from memory                    */
    }
    //enableInterrupts();                               /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                Static uThread Init                   */
/* **************************************************** */
static utcb *uthread_init(uthread_func_t func, void *arg)
{
    struct uthread_tcb *tcb = malloc(sizeof(utcb));     /* Alloc thread control block structure     */
    tcb->uctx  = malloc(sizeof(uthread_ctx_t));         /* Alloc user-level thread context struct   */
    tcb->func  = func;                                  /* Set the TCB function pointer             */
    tcb->arg   = arg;                                   /* Set the TCB function argument pointer    */
    tcb->state = READY;                                 /* Set the TCB state                        */
    return tcb;                                         /* Return pointer to the TCB                */
}
/* **************************************************** */
/* **************************************************** */
/*                   uThread Create                     */
/* **************************************************** */
int uthread_create(uthread_func_t func, void *arg)
{                                                       /* See Anderson Textbook Figure 4.13        */
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
/*                    uThread Exit                      */
/* **************************************************** */
void uthread_exit(void)
{                                                       /* See Anderson Textbook 4.6.2              */
    utcb *me, *next;                                    /* Declare TCB pointers                     */
    //disableInterrupts();                              /* TODO not sure how to do this yet         */
    queue_dequeue(RunQ, (void **) &me);                 /* Remove thread from the running queue     */
    uthread_enqueue(me, DONE);                          /* Set the state, add to done queue         */
    queue_dequeue(ReadyQ, (void **) &next);             /* Get the next TCB from the ready queue    */
    uthread_enqueue(next, RUNNING);                     /* Set the state, add to running queue      */
    uthread_ctx_switch(me->uctx, next->uctx);           /* Switch context of threads                */
    //enableInterrupts();                               /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                    uThread Block                     */
/* **************************************************** */
void uthread_block(void)
{
    utcb *nextTCB, *runTCB;                             /* Declare TCB pointers                     */
    printf("DEBUG: uthread_block()\n");
    //disableInterrupts();                              /* TODO not sure how to do this yet         */
    queue_dequeue(RunQ,   (void **) &runTCB);           /* Remove thread from the running queue     */
    queue_dequeue(ReadyQ, (void **) &nextTCB);          /* Get the next TCB from the Ready queue    */
    uthread_enqueue(runTCB, BLOCKED);                   /* Change state, add to wait queue          */
    uthread_enqueue(nextTCB, RUNNING);                  /* Change state, add to running queue       */
    uthread_ctx_switch(runTCB->uctx, nextTCB->uctx);    /* Switch context of runTCB and nextTCB     */
    //enableInterrupts();                               /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                    uThread Unblock                   */
/* **************************************************** */
void uthread_unblock(struct uthread_tcb *uthread)
{
    printf("DEBUG: uthread_unblock()\n");
    //disableInterrupts();                              /* TODO not sure how to do this yet         */
    queue_delete(WaitQ, (void *) uthread);              /* Remove the tcb from the waiting queue    */
    uthread->state = READY;
    uthread_enqueue(uthread, READY);                    /* Queue the tcb to the ready queue         */
    //enableInterrupts();                               /* TODO not sure how to do this yet         */
}
/* **************************************************** */
/* **************************************************** */
/*                  uThread Current                     */
/* **************************************************** */
struct uthread_tcb *uthread_current(void)
{
    struct uthread_tcb *current;                        /* TODO try not use queue dequeue/enqueue here  */
    queue_dequeue(RunQ, (void **) &current);            /* Get the currently running TCB from the queue */
    queue_enqueue(RunQ, (void *) current);              /* Add back to the running queue                */
    return current;                                     /* Return pointer to currently running thread   */
}
/* **************************************************** */
/* **************************************************** */
/*                    uThread Start                     */
/* **************************************************** */
void uthread_start(uthread_func_t start, void *arg)
{
    unsigned int i;
    queue_t *QArray[]={&ReadyQ, &RunQ, &WaitQ, &DoneQ}; /* Declare array of queue pointers              */

    for (i = 0; i < NQUEUES; i++)                       /* For each queue in QArray[]                   */
        *QArray[i] = queue_create();                    /* Alloc/Init global pointer to each queue      */

    /* Create idle & 1st thread. Then loop */
    utcb *idleThread = uthread_init(NULL, NULL);        /* Alloc/Init a TCB to the idle thread          */
    uthread_enqueue(idleThread, RUNNING);               /* Set the state, add to running queue          */
    uthread_create(start, arg);                         /* Create 1 thread, auto-add to ready queue     */

    while(queue_length(ReadyQ))   uthread_yield();      /* Ready threads exist? Switch to next thread   */

    /* Memory Cleanup */
    queue_delete(RunQ, (void *) idleThread);            /* Remove idleThread from the running queue     */
    free(idleThread->uctx);                             /* Free user-level thread context               */
    free(idleThread);                                   /* Free TCB from memory                         */
    for (i = 0; i < NQUEUES; i++) {                     /* For each queue in QArray[]                   */
        if(queue_destroy(*QArray[i]))                   /* Destroy the queue                            */
            printf("Failed to destroy queue %d\n", i);  /* Debug Statement, Check for memory leaks    */
    }
}
/* **************************************************** */
