/* testhRemove.c --- 
 * 
 * 
 * Author: Taylor M. Olson
 * Created: Sun Oct 13 14:57:29 2019 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "queue.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct person_t {
	char name[15];
	int age;
} person_t;

struct person_t *make_person(char *name, int age) {
	struct person_t *p;
	if (!(p = (struct person_t *)malloc(sizeof(person_t)))) {
		printf("error creating person");
		return NULL;
	}
	strcpy(p->name, name);
	p->age = age;
	return p;
}

bool searchByName(void *p, const void *n) {
	struct person_t *person = (struct person_t *)p;
	char *nameLookingFor = (char *)n;
	char *name = person->name;

	if(strcmp(name, nameLookingFor) == 0) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	// Make hashtable
	hashtable_t *hp = hopen(10);

	person_t *person1 = make_person("Sudharsan", 18);
	person_t *person2 = make_person("Taylor", 20);
	person_t *person3 = make_person("James", 23);
	person_t *person4 = make_person("Erin", 27);

	hput(hp, (void *)person1, (const char *)person1->name, sizeof(person1->name));
	hput(hp, (void *)person2, (const char *)person2->name, sizeof(person2->name));
	hput(hp, (void *)person3, (const char *)person3->name, sizeof(person3->name));
	hput(hp, (void *)person4, (const char *)person4->name, sizeof(person4->name));

	if (hremove(hp, searchByName, (const char *)person1->name, sizeof(person1->name)) == NULL) {
		printf("Failure: Could not remove Sud\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person1->name, sizeof(person1->name)) != NULL) {
		printf("Failure: Could not remove Sud\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person3->name, sizeof(person3->name)) == NULL) {
		printf("Failure: Could not remove James\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person3->name, sizeof(person3->name)) != NULL) {
		printf("Failure: Could not remove James\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person4->name, sizeof(person4->name)) == NULL) {
		printf("Failure: Could not remove Erin\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person4->name, sizeof(person4->name)) != NULL) {
		printf("Failure: Could not remove Erin\n");
		exit(EXIT_FAILURE);
	}

	if (hremove(hp, searchByName, (const char *)person2->name, sizeof(person2->name)) == NULL) {
    printf("Failure: Could not remove Tay\n");                                                   
    exit(EXIT_FAILURE);
  }
	
  if (hremove(hp, searchByName, (const char *)person2->name, sizeof(person2->name)) != NULL) {
    printf("Failure: Could not remove Tay\n");
    exit(EXIT_FAILURE);
  }

	hclose(hp);
	free(person1);
	free(person2);
	free(person3);
	free(person4);

	printf("testhRemove Succeeded");
	exit(EXIT_SUCCESS);
}

