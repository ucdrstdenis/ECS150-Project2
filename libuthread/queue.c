#include <stdint.h>
#include <stdlib.h>

#include "queue.h"                                      /* queue_t is a pointer to a queue      */


/* **************************************************** */
/*                   Queue Structures                   */
/* **************************************************** */
typedef struct node {                                   /* Thread item                          */
    void *data;                                         /* Pointer to data                      */
    struct node *next;                                  /* Pointer to next thread               */
} node;

typedef struct queue {                                  /* Define queue FIFO structure          */
    node *head;                                         /* pointer to FIFO front                */
    node *tail;                                         /* Pointer to FIFO back                 */
} queue;
/* **************************************************** */
/* **************************************************** */
/*                     Queue Create                     */
/* **************************************************** */
queue_t queue_create(void)
{
    queue_t Q = (queue*) malloc(sizeof(queue));         /* Allocate memory for the queue        */
    if (Q == NULL) return Q;                            /* Return NULL pointer if malloc fails  */

    Q->head = NULL;                                     /* Set the head                         */
    Q->tail = NULL;                                     /* Set the tail                         */
    return Q;                                           /* Return the pointer                   */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Destroy                     */
/* **************************************************** */
int queue_destroy(queue_t queue)
{
    if (queue == NULL)          return -1;              /* Passed NULL, return fail             */
    if (queue->head != NULL)    return -1;              /* Queue is not empty, return fail      */
    if (queue->tail != NULL)    return -1;              /* Queue is not empty, return fail      */

    free(queue);                                        /* Deallocate the memory                */
    return 0;                                           /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Enqueue                     */
/* **************************************************** */
int queue_enqueue(queue_t queue, void *data)
{
    node *pnode = (node*) malloc(sizeof(node));         /* Allocate memory for thread           */

    if (queue == NULL)          return -1;              /* Passed NULL, return fail             */
    if (pnode == NULL)          return -1;              /* Failed to malloc, return fail        */

    if (queue->head == NULL)                            /* Check if the queue is empty 	        */
        queue->head = pnode;                            /* Point the head to the new node 	    */
    else
        queue->tail->next = pnode;                      /* Point current tail to new node       */

    queue->tail = pnode;                                /* Point the tail to the new node       */
    pnode->next = queue->head;                          /* Last node points back to the head    */
    pnode->data = data;                                 /* Set the pointer to the data          */

    return 0;                                           /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Dequeue                     */
/* **************************************************** */
int queue_dequeue(queue_t queue, void **data)
{
    if (queue == NULL)          return -1;              /* Passed NULL, return fail             */
	/* TODO Phase 1 */

    return 0;                                           /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Delete                      */
/* **************************************************** */
int queue_delete(queue_t queue, void *data)
{
    /* JP says only the internal node should be freed            */
    /* You cannot make any assumption on the *data that is given. */
    /* In other words, this data doesn't belong to the queue API */

    if (queue == NULL)          return -1;              /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return -1;              /* Queue head is NULL, return fail      */
    if (queue->tail == NULL)    return -1;              /* Queue tail is NULL, return fail      */
    /* TODO Phase 1 */



    return 0;                                           /* Return success                       */

}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Iterate                     */
/* **************************************************** */
int queue_iterate(queue_t queue, queue_func_t func)
{
    if (queue == NULL)          return -1;              /* Passed NULL queue, return fail       */
    if (func == NULL)           return -1;              /* Passed NULL func, return fail        */
	/* TODO Phase 1 */


    return 0;                                           /* Return success                       */
}
/* **************************************************** */

/* **************************************************** */
/*                     Queue Length                     */
/* **************************************************** */
int queue_length(queue_t queue)
{
    int length = 1;
    node *curr;

    if (queue == NULL)          return -1;              /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return  0;              /* Queue head is NULL, return 0         */
    if (queue->tail == NULL)    return -1;              /* Q head not NULL, tail is NULL, fail  */

    curr = queue->head;                                 /* Current node to iterate over         */

    while(curr->next != queue->head) {                  /* While more items in the list         */
        curr = curr->next;                              /* Get the next node in the list        */
        length++;                                       /* Increment the length                 */
        if (curr == NULL)       return -1;              /* Node improperly set, return fail     */
    }

    return length;                                      /* Return the length of the queue       */
}
/* **************************************************** */

