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
    printf("trouble putting in an item");                             
    exit(EXIT_FAILURE);                                                      
  }

	printf("success putting in an item to a nonempty list and of different type");

	
	printf("testPut succeeded");
  qclose(qt);   

}
