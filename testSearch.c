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
#include <string.h>
#include <stdbool.h>

struct person_t{
	char name[15];
	int age;
} person_t;



struct person_t *make_person(char *name, int age){
	struct person_t *p;
	if (!(p = (struct person_t*)malloc(sizeof(person_t)))){
		printf("error creating person");
		return NULL;
	}
	strcpy(p->name, name);
	p->age = age;
	return p;
}


bool searchByName(void *p, const void *n){
	struct person_t *person = (struct person_t*)p;
	char *nameLookingFor = (char*)n;
	char *name = person->name;
	if (strcmp(name, nameLookingFor) == 0)
		return true;
	else{
		return false;
	}
}
int main(void){

	queue_t *qp;
	qp = qopen();

	struct person_t *person1;
	struct person_t *person2;
	struct person_t *person3;
	struct person_t *person4;


	person1 = make_person("Jim", 15);
	person2 = make_person("Jessica", 37);
	person3 = make_person("Jeremy", 18);
	person4 = make_person("Julian", 19);
	qput(qp, person1);
	qput(qp, person2);
	qput(qp, person3);
	qput(qp, person4);

	if (qsearch(qp, searchByName, "Jeremy") == NULL){
		printf("failure\n");
		exit(EXIT_FAILURE);
	}

	if(qsearch(qp, searchByName, "NOLAN") != NULL){
		printf("failure\n");
		exit(EXIT_FAILURE);
	}

	// Make sure we are returning the right values when we search for it
	char *returnedName = qsearch(qp, searchByName, "Jessica");
	if (strcmp(returnedName, "Jessica") !=0){
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	

	
	qclose(qp);
	free(person1);
	free(person2);
	free(person3);
	free(person4);
	free(returnedName);
	
	printf("testSearch.c Succeeded\n");
	exit(EXIT_SUCCESS);
}
