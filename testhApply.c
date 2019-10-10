/* testhOpen.c --- 
 * 
 * 
 * Author: James D. Fleming
 * Created: Mon Oct  7 19:53:57 2019 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
void makeDouble(void *ep){
	*(double *)ep = *(double *)(ep) *2;
}

int main(void){
	hashtable_t *hash = hopen(10);
	double x = 2.0;
	double y = 5.0;
	hput(hash,(void *)&x,"2",sizeof("2"));
	hput(hash,(void *)&y,"5",sizeof("5"));
	happly(hash, makeDouble);
	if (x != 4){
		printf("testhApply.c failed \n");
		exit(EXIT_FAILURE);
	}
	if (y != 10){
		printf("testhApply.c failed \n");
		exit(EXIT_FAILURE);
	}
	hclose(hash);
	printf("testhApply succeded\n");
	exit(EXIT_SUCCESS);
}
