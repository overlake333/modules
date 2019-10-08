/* testApply.c --- 
 * 
 * 
 * Author: Sudharsan Balasubramani
 * Created: Oct 8  20:42:54 2019 (-0400)
 * Version: 1.0
 * 
 * Description: Tests the qapply function of the queue ADT. 
 * 
 */
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void square(int *num){
  *num *= *num;
}

int main(void){
  queue_t *qt;
  qt = qopen();
  int x = 2.0;
  int y = 420;
  
  qput(qt,(void*)&x);
  qput(qt,(void*)&y);

  qapply(qt, square);

  int x2 = (int *)(qget(qt));
  int y2 = (int *)(qget(qt));

  if(((x*x) != x2) && ((y*y) != y2)){
    printf("YOU HAVE FAILED THIS CITY!");
    exit(EXIT_FAILED);
  } 
  
  
  printf("testApply succeeded\n");
  qclose(qt);   
  exit(EXIT_SUCCESS);
}
