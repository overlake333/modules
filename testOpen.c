/* testOpen.c --- 
 * 
 * 
 * Author: James D. Fleming
 * Created: Fri Oct  4 16:19:47 2019 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
int main(void){
	queue_t *qt;
	qt = qopen();
	if (qt == NULL){
		printf("bad vibes all around\n");
		
		exit(EXIT_FAILURE);
	}
	double x = 2.0;
	
	
	if ((qput(qt,(void*)&x)) !=0){
		printf("trouble putting in an item");
		exit(EXIT_FAILURE);
	}
	printf("success\n");

	qclose(qt);
	exit(EXIT_SUCCESS);
}
