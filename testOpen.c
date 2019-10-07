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
	queue_t *qt2;
	qt2 = qopen();
	if (qt == NULL){
		printf("failure creating queue\n");
		exit(EXIT_FAILURE);
	}
	if (qt2 == NULL){
		printf("failure creating a second queue\n");
		exit(EXIT_FAILURE);
	}

	
	free(qt);
	free(qt2);
	printf("testOpen succeeded\n");
	exit(EXIT_SUCCESS);
}
