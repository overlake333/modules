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
	hashtable_t *hash = hopen(0);
	if (hash == NULL){
		printf("failure, hashtable came back null\n");
		exit(EXIT_FAILURE);
	}

	hclose(hash);
	printf("testhOpen succeded\n");
	exit(EXIT_SUCCESS);
}
