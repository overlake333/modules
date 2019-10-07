/* testPut.c --- 
 * 
 * 
 * Author: James D. Fleming
 * Created: Sun Oct  6 20:42:54 2019 (-0400)
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
	double x = 2.0;
	int y = 420;
	
  if ((qput(qt,(void*)&x)) !=0){                                        
    printf("trouble putting in an item to empty list \n");          
    exit(EXIT_FAILURE);                                                      
  }

	
  printf("success putting in an item to empty list\n");

	if ((qput(qt,(void*)&y)) !=0){                                        
    printf("trouble putting in an item\n");                             
    exit(EXIT_FAILURE);                                                      
  }

	printf("success putting in an item to a nonempty list and of different type\n");
	
	queue_t *qte;
	qte = qopen();
	qclose(qte);
	if (qte == NULL){
		printf("we should be stopping here!!!!\n");
	}

	// qte was opened but is now closed. qput should return nonzero
	//if ((qput(qte, (void*)&z)) == 0){
		//printf("failure: tried to add to a null queue\n");
	//	exit(EXIT_FAILURE);
	//	}

	printf("successfully exited before trying to add to an empty queue\n");
	printf("testPut succeeded\n");
  qclose(qt);   
	exit(EXIT_SUCCESS);
}
