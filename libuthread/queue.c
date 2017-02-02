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
/*                    Queue Create                      */
/* **************************************************** */
queue_t queue_create(void)
{
    queue_t Q = (queue*) malloc(sizeof(queue));         /* Allocate memory for the queue        */
    if (Q == NULL) return Q;                            /* malloc failed, return NULL pointer   */

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
    node *pnode = (node*) malloc(sizeof(node));         /* Allocate memory for node             */

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
    node *curr, *prev;                                  /* Current node to iterate over         */

    if (queue == NULL)          return -1;              /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return -1;              /* Queue head is NULL, return fail      */
    if (queue->tail == NULL)    return -1;              /* Queue tail is NULL, return fail      */

    curr = queue->head;                                 /* Current node is the head             */
    prev = NULL;                                        /* Previous node                        */

    while(curr->next != queue->head) {                  /* While more items in the queue        */
        if (curr->data == data) {                       /* If data is found                     */
            prev = curr->next;                          /* Store pointer to next node           */
            curr->data = curr->next->data;              /* Overwrite data w/ next node data     */
            curr->next = curr->next->next;              /* Overwrite next w/ next node next     */
            free(prev);                                 /* Delete the next node                 */
            if (curr->next == queue->head)              /* If node deleted was the tail         */
                queue->tail = curr;                     /* Update the tail pointer              */
            return 0;                                   /* Data was found, return success       */
        }
        prev = curr;                                    /* Save the node as the previous node   */
        curr = curr->next;                              /* Iterate to next node                 */
    }

    if(curr->data == data) {                            /* Check last item in queue             */
        if (curr == queue->head) {                      /* If its the head, only 1 item in Q    */
            queue->head = NULL;                         /* Nullify the head                     */
            queue->tail = NULL;                         /* Nullify the tail                     */
        } else {                                        /* Otherwise, will delete current tail  */
            queue->tail = prev;                         /* Update the queue's tail pointer      */
            prev->next = queue->head;                   /* Set new tail->next to point to head  */
        }
        free(curr);                                     /* Delete the node                      */
        return 0;                                       /* Data was found, return success       */
    }

    return -1;                                          /* Data not found, return fail          */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Iterate                     */
/* **************************************************** */
int queue_iterate(queue_t queue, queue_func_t func)
{
    if (queue == NULL)          return -1;              /* Passed NULL queue, return fail       */
    if (func == NULL)           return -1;              /* Passed NULL function, return fail    */
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
    if (queue->head == NULL)    return  0;              /* Queue head is NULL, length is 0      */
    if (queue->tail == NULL)    return -1;              /* Q head not NULL, tail is NULL, fail  */

    curr = queue->head;                                 /* Current node to iterate over         */

    while(curr->next != queue->head) {                  /* While more items in the queue        */
        curr = curr->next;                              /* Get the next node in the queue       */
        length++;                                       /* Increment the length                 */
        if (curr == NULL)       return -1;              /* Node improperly set, return fail     */
    }

    return length;                                      /* Return the length of the queue       */
}
/* **************************************************** */
