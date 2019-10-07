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

//typdef struct person

int main(void){

	queue_t *qp;
	qp = qopen();
	qclose(qp);
	exit(EXIT_SUCCESS);
}
