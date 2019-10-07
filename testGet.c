/* testClose.c --- 
 * 
 * 
 * Author: James D. Fleming
 * Created: Sun Oct  6 20:59:25 2019 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){

	queue_t *qp;
	qp = qopen();
	double x = 3.0;
	double y = 455.0;
	double z = 569.0;
	qput(qp,(void*)&x);
	qput(qp,(void*)&y);
	qput(qp,(void*)&z);

	double *x1 = (double*)qget(qp);
	double *y1 = (double*)qget(qp);
	double *z1 = (double*)qget(qp);
	double *shouldbeNull = (double*)qget(qp);


	if ((*x1 != x) || (*y1 != y) || (*z1 !=z)){
		printf("failure getting element from queue\n");
		exit(EXIT_FAILURE);
	}
	if (shouldbeNull != NULL){
		printf("failure: qget tried to get from an empty queue");
		exit(EXIT_FAILURE);
	}
	
	
	printf("testGet succeeded and got all elements as expected\n");
	exit(EXIT_SUCCESS);
}
