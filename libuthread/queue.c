#include <stdint.h>
#include <stdlib.h>

#include "queue.h"                                      /* queue_t is a pointer to a queue      */

/* **************************************************** */
/*                   Queue #DEFINES                     */
/* **************************************************** */
#define FAIL        -1                                  /* Fail code                            */
#define SUCCESS      0                                  /* Success code                         */

/* **************************************************** */
/*                   Queue Structures                   */
/* **************************************************** */
typedef struct node {                                   /* Thread item                          */
    void *data;                                         /* Pointer to data                      */
    struct node *next;                                  /* Pointer to next thread               */
} node;

typedef struct queue {                                  /* Define queue FIFO structure          */
    node *head;                                         /* Pointer to FIFO front                */
    node *tail;                                         /* Pointer to FIFO back                 */
    int length;                                         /* Holds length of the queue            */
} queue;
/* **************************************************** */
/* **************************************************** */
/*                    Queue Create                      */
/* **************************************************** */
queue_t queue_create(void)
{
    queue_t Q = (queue*) malloc(sizeof(queue));         /* Allocate memory for the queue        */
    if (Q == NULL) return Q;                            /* Malloc failed, return NULL pointer   */

    Q->head = NULL;                                     /* Set the head                         */
    Q->tail = NULL;                                     /* Set the tail                         */
    Q->length = 0;                                      /* Set the queue length                 */

    return Q;                                           /* Return the pointer                   */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Destroy                     */
/* **************************************************** */
int queue_destroy(queue_t queue)
{
    if (queue == NULL)          return FAIL;            /* Passed NULL, return fail             */
    if (queue->head != NULL)    return FAIL;            /* Queue is not empty, return fail      */
    if (queue->tail != NULL)    return FAIL;            /* Queue is not empty, return fail      */
    if (queue->length != 0)     return FAIL;            /* Queue length isn't 0, return fail    */

    free(queue);                                        /* Deallocate the memory                */
    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Enqueue                     */
/* **************************************************** */
int queue_enqueue(queue_t queue, void *data)
{
    node *pnode = (node*) malloc(sizeof(node));         /* Allocate memory for a new node       */

    if (queue == NULL)          return FAIL;            /* Passed NULL, return fail             */
    if (pnode == NULL)          return FAIL;            /* Failed to malloc, return fail        */

    if (queue->head == NULL)                            /* Check if the queue is empty 	        */
        queue->head = pnode;                            /* Point the head to the new node       */
    else                                                /* If it is not empty                   */
        queue->tail->next = pnode;                      /* Point current tail to new node       */

    pnode->data = data;                                 /* Set the pointer to the data          */
    pnode->next = queue->head;                          /* Last node points back to the head    */
    queue->tail = pnode;                                /* Point the tail to the new node       */
    queue->length++;                                    /* Increment the queue  length          */

    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Dequeue                     */
/* **************************************************** */
int queue_dequeue(queue_t queue, void **data)
{
    if (queue == NULL)          return FAIL;            /* Passed NULL, return fail             */
    if (queue->head == NULL)    return FAIL;            /* Queue head is null, return fail      */
    if (queue->tail == NULL)    return FAIL;            /* Queue tail is null, return fail      */

    *data = queue->head->data;                          /* Store the pointer to the data        */

    if(queue_delete(queue, queue->head->data))          /* Remove the node from the queue       */
        return FAIL;                                    /* queue_delete failed, return fail     */

    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                    Queue Delete                      */
/* **************************************************** */
int queue_delete(queue_t queue, void *data)
{
    node *curr, *tmp;                                   /* Current node to iterate over         */

    if (queue == NULL)          return FAIL;            /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return FAIL;            /* Queue head is NULL, return fail      */

    curr = queue->head;                                 /* Current node is the head             */
    tmp = NULL;                                         /* Temporary node                       */

    while(curr->next != queue->head) {                  /* While more items in circular queue   */
        if (curr->data == data) {                       /* If data is found                     */
            tmp = curr->next;                           /* Store pointer to next node           */
            curr->data = tmp->data;                     /* Overwrite data w/ next node data     */
            curr->next = tmp->next;                     /* Overwrite next w/ next node next     */
            free(tmp);                                  /* Delete the tmp node                  */
            if (curr->next == queue->head)              /* If node deleted was the tail         */
                queue->tail = curr;                     /* Update the tail pointer              */
            queue->length--;                            /* Update the queue length              */
            return SUCCESS;                             /* Data was found, return success       */
        }
        tmp = curr;                                     /* Save node as temporary node          */
        curr = curr->next;                              /* Iterate through the circular queue   */
    }                                                   /* End while loop                       */

    if(curr->data == data) {                            /* Check last item in circular queue    */
        if (curr == queue->head) {                      /* If its the head, only 1 item in Q    */
            queue->head = NULL;                         /* Nullify the head                     */
            queue->tail = NULL;                         /* Nullify the tail                     */
        } else {                                        /* Otherwise, will delete current tail  */
            queue->tail = tmp;                          /* Update the queue's tail pointer      */
            tmp->next = queue->head;                    /* Set new tail->next to point to head  */
        }
        free(curr);                                     /* Delete the node                      */
        queue->length--;                                /* Update the queue length              */
        return SUCCESS;                                 /* Data was found, return success       */
    }

    return FAIL;                                        /* Data not found, return fail          */
}
/* **************************************************** */
/* **************************************************** */
/*               Queue Iterate (UNUSED)                 */
/* **************************************************** */
int queue_iterate(queue_t queue, queue_func_t func)
{
    node *curr, *tmp;                                   /* Declare node pointers                */

    if (func == NULL)           return FAIL;            /* Passed NULL function, return fail    */
    if (queue == NULL)          return FAIL;            /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return SUCCESS;         /* Nothing 2 iterate, return success    */

    curr = queue->head;                                 /* Set node pointer to the head of queue*/
    tmp  = NULL;                                        /* Set temporary pointer                */

    while (curr->next != queue->head) {                 /* Iterate through the circular queue   */
        tmp = curr->next;                               /* Store next pointer in case deleted   */
        func(curr->data);                               /* Call the function                    */

        if (tmp == curr->next)                          /* If the node was NOT overwritten      */
            curr = curr->next;                          /* Iterate to next node                 */
    }                                                   /* End while loop                       */

    func(curr->data);                                   /* Call function for last item in queue */

    return SUCCESS;                                     /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                     Queue Length                     */
/* **************************************************** */
int queue_length(queue_t queue)
{
    if (queue == NULL)          return FAIL;            /* Passed NULL queue, return fail       */
    if (queue->head == NULL)    return SUCCESS;         /* Queue head is NULL, length is 0      */
    if (queue->tail == NULL)    return FAIL;            /* Q head not NULL, tail is NULL, fail  */

    return queue->length;                               /* Return the length of the queue       */
}
/* **************************************************** */
