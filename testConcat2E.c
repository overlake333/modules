/* testConcat2E
 *
 *
 *
 * Author: Sudharsan B.
 * Created: Thu Oct 10
 * Version: 1.0
 *
 *
 *
 * Desc. concatenating two empty queues
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
int main(void){
  //create and fill two queues                                                                                                          
  queue_t *qt;
  qt = qopen();
  queue_t *qt2;
  qt2 = qopen();
	
  int x = 1;
  int y = 2;
  int a = 3;
  int b = 4;

  // qput(qt,(void*)&x);
  // qput(qt, (void*)&y);
  // qput(qt2, (void*)&a);
  // qput(qt2, (void*)&b);
	
  // call qconcat                                                                                                                       
  qconcat(qt, qt2);
  // Now grab the elements from qt and make sure they come out in the expected order                                                    
  if ((*qt).front != NULL){
    printf("failure: concat did no attach the queues in the right order");
  }
  //only close qt because qt2 should have been closed by concat                                                                         
  qclose(qt);
  printf("testCat succeeded!\n");
  exit(EXIT_SUCCESS);
}

