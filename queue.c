/* queue.c --- 
 * 
 * 
 * Author: James D. Fleming
 * Created: Fri Oct  4 13:47:51 2019 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "queue.h"
#include <stdint.h>                                                                             
#include <stdbool.h>                                                                            
#include <stdio.h>
#include <stdlib.h>

typedef struct qElement_t {
	// every element holds a value which can be anything (double, car, person, cat) and a next Pointer
	void *value;
	void *next;

} qElement_t;


typedef struct myQueue_t{
	//Since we are hiding what a queue object is we need another
	//structure to hold the queue front and back pointers Everytime we
	//get a queue_t we need to convert it to a myQueue_t and every time
	//we send it back we need to do this as well
	qElement_t *front;
	qElement_t *back;
	
} myQueue_t;

static myQueue_t *makeQueue(){
	myQueue_t *qt;
	if (!(qt =(myQueue_t*)malloc(sizeof(myQueue_t)))){
		printf("error creating queue");
		return NULL;
	}
	qt->front =NULL;
	qt->back = NULL;
	return qt;
}
// method for creating a qElement given some sort of value elementp
static qElement_t *makeElement(void *elementp){
	qElement_t *e;
	if (!(e=(qElement_t*)malloc(sizeof(qElement_t)))){
		printf("error creating element of queue");
		return NULL;
	}
	e->next = NULL;
	e->value = elementp;
	return e;
}

	
/* create an empty queue */                                                                     
queue_t* qopen(void){
	queue_t *qt = (void*)makeQueue();
	
	return qt;
}
                                                                                                
/* deallocate a queue, frees everything in it */
 void qclose(queue_t *qp){
	 // Loop through all the elements of the queue freeing them up
	 myQueue_t *mqp = (myQueue_t*)qp; //Switching queue_t to myQueue_t here
	 qElement_t *elementPointer = mqp->front;
	 qElement_t *nextElement;
	 // Loop through all the pointers until we reach the end. Keep a
	 // temporary nextElement so that we can delete the current element
	 // and still have reference to that element's next pointer
	 while ( elementPointer !=NULL){
	 nextElement = elementPointer->next;
	 free(elementPointer);
	 elementPointer = nextElement;
	 }
	 // Finally free up the queue itself
	 free(mqp);
	 
 } 
                                                                                                
/* put element at the end of the queue */
/*  * returns 0 is successful; nonzero otherwise */
/*  *\/ */
 int32_t qput(queue_t *qp, void *elementp){
	 myQueue_t *mqp = (myQueue_t*)qp;
	 qElement_t *e;
	 // make sure we can successfully make an qElement
	 if((e=makeElement(elementp)) == NULL){
		 return 1;
	 }

	 // CASE if queue is currently empty
	 if (mqp->front == NULL){
		 // set both front and back pointers to e;
		 mqp->front = e;
		 mqp->back = e;
	 }else{
		 // if queue is not empty update next of current back pointer and switch backpointer to new element
		 (mqp->back)->next = e;
		 mqp->back = e;
	 }
	 return 0;
 }
                                                                                                
/* /\* get the first first element from queue, removing it from the queue *\/ */
/* void* qget(queue_t *qp){ */

/* } */
                                                                                                
/* /\* apply a function to every element of the queue *\/ */
/* void qapply(queue_t *qp, void (*fn)(void* elementp)){ */

/* } */
                                                                                                
/* /\* search a queue using a supplied boolean function */
/*  * skeyp -- a key to search for */
/*  * searchfn -- a function applied to every element of the queue */
/*  *          -- elementp - a pointer to an element */
/*  *          -- keyp - the key being searched for (i.e. will be */
/*  *             set to skey at each step of the search */
/*  *          -- returns TRUE or FALSE as defined in bool.h */
/*  * returns a pointer to an element, or NULL if not found */
/*  *\/ */
/* void* qsearch(queue_t *qp, */
/*               bool (*searchfn)(void* elementp,const void* keyp), */
/*               const void* skeyp){ */

/* } */
                                                                                                
/* /\* search a queue using a supplied boolean function (as in qsearch), */
/*  * removes the element from the queue and returns a pointer to it or */
/*  * NULL if not found */
/*  *\/ */
/* void* qremove(queue_t *qp, */
/*               bool (*searchfn)(void* elementp,const void* keyp), */
/*               const void* skeyp){ */

/* } */
                                                                                                
/* /\* concatenatenates elements of q2 into q1 */
/*  * q2 is dealocated, closed, and unusable upon completion */
/*  *\/ */
/* void qconcat(queue_t *q1p, queue_t *q2p){ */

/* } */
                                                                                                
                                                                                                
                                                                
