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


int main(void){
	hashtable_t *hash = hopen(10);
	double x = 2.0;
	double y = 5.0;
	if ((hput(hash,(void *)&x,(const char *)&x,sizeof(x)))!=0){
		printf("testhPutAgainSameAddress failed\n");
		exit(EXIT_FAILURE);
	}
	if ((hput(hash,(void *)&y, (const char *)&x,sizeof(x)))!=0){
		printf("testhPutAgainSameAdress failed\n");
		exit(EXIT_FAILURE);
	}
	
	hclose(hash);
	printf("testhPutAgainSameAddress succeded\n");
	exit(EXIT_SUCCESS);
}
