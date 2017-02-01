#include <stdint.h>
#include <stdlib.h>

#include "queue.h"                                      /* queue_t is a pointer to a queue      */


/* **************************************************** */
/*                   Queue Structures                   */
/* **************************************************** */
typedef struct thread {                                 /* Thread item 			  	            */
    void *data;                                         /* Pointer to data 		  	            */
    struct thread *next;                                /* Pointer to next thread 	  	        */
} thread;

typedef struct queue {                                  /* Define queue FIFO structure          */
	thread *head;                                       /* pointer to FIFO front                */
	thread *tail;                                       /* Pointer to FIFO back                 */
} queue;
/* **************************************************** */
/* **************************************************** */
/*                     Queue Create                     */
/* **************************************************** */
queue_t queue_create(void)
{
    queue_t Q = (queue*) malloc(sizeof(queue));         /* Allocate memory for the queue 	    */
    if (Q == NULL) return Q;                            /* Return NULL pointer if malloc fails  */

    //Q->head = NULL;                                   /* Set the head                   	    */
    //Q->tail = NULL;                                   /* Set the tail                   	    */
    return Q;                                           /* Return the pointer             	    */
}
/* **************************************************** */
/* **************************************************** */
/* 			            Queue Destroy                   */
/* **************************************************** */
int queue_destroy(queue_t queue)
{
    /* JP says to assume queue is empty before deleting */
    /* Return an error if it's not */

    /* Why are we returning ints? Do we need 32 bits??? char should do */
    /* Unless this is just good practice on newer processors    */

    if (queue == NULL) 	           return -1;
    if (queue->head != NULL)       return -1;
    if (queue->tail != NULL)       return -1;

    
    free(queue);                                        /* Dealloc the memory                   */
    
    return 0;                                           /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/* 		            Queue Enqueue 			            */
/* **************************************************** */
int queue_enqueue(queue_t queue, void *data)
{
    if (queue == NULL) return -1;                       /* Passed NULL, return fail             */

    thread *pthread = (thread*) malloc(sizeof(thread)); /* Allocate memory for thread           */
    if (pthread == NULL) return -1;                     /* Failed to malloc                     */

    pthread->next = NULL;
    pthread->data = data;

    if (queue->head == NULL) {                          /* Check if the queue is empty 	        */
        queue->head = pthread;                          /* Point the head to pthread 	        */
        queue->tail = pthread;                          /* Point the tail to pthread 	        */
    } else {
        queue->tail->next = pthread;                    /* Point tail's next to pthread         */
        queue->tail = pthread;                          /* Point the tail to pthread 	        */
    }	

    /* TODO Check for possible fails */
    return 0;                                           /* Return success                       */
}
/* **************************************************** */
/* **************************************************** */
/*                      Queue Dequeue                   */
/* **************************************************** */
int queue_dequeue(queue_t queue, void **data)
{
    if (queue == NULL) return -1;                       /* Passed NULL, return fail             */
	/* TODO Phase 1 */
}
/* **************************************************** */
/* **************************************************** */
/*                       Queue Delete                   */
/* **************************************************** */
int queue_delete(queue_t queue, void *data)
{
    /* JP says only the internal node should be freed            */
    /* You cannot make any asumption on the *data that is given. */
    /* In other words, this data doesn't belong to the queue API */
    if (queue == NULL) return -1;                       /* Passed NULL queue, return fail       */




    return 0;                                           /* Return success                       */

}
/* **************************************************** */
/* **************************************************** */
/*                  Queue Iterate                       */
/* **************************************************** */
int queue_iterate(queue_t queue, queue_func_t func)
{
    if (queue == NULL)  return -1;                      /* Passed NULL queue, return fail       */
    if (func == NULL)   return -1;                      /* Passed NULL func, return fail        */
	/* TODO Phase 1 */


    return 0;                                           /* Return success                       */
}
/* **************************************************** */

/* **************************************************** */
/* 			Queue Length                                */
/* **************************************************** */
int queue_length(queue_t *queue)
{
    if (queue == NULL) return -1;                       /* Passed NULL queue, return fail       */
	/* TODO Phase 1 */


    return 0;                                           /* Return success                       */
}
/* **************************************************** */

