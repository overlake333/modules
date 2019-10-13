/* 
 * testhSearch.c -- tests hsearch
 * 
 * 
 * Author: Sudharsan Balasubramani
 * Created: Fri Oct 11 3:30 PM
 * Version: 1.0
 *
 *  
 * 
 * Description: Tests Search
 */

#include "queue.h"
#include "hash.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct person_t{
  char name[15];
  int age;
} person_t;

struct person_t *make_person(char *name, int age){
  struct person_t *p;
  if(!(p = (struct person_t *)malloc(sizeof(person_t)))){
    printf("error creating person");
    return NULL;
  }
  strcpy(p->name, name);
  p->age = age;
  return p;
}


bool searchByName(void *p, const void *n){
  struct person_t *person = (struct person_t *)p;
  char *nameLookingFor = (char *)n;
  char *name = person->name;
  if(strcmp(name, nameLookingFor) == 0)
    return true;
  else
    return false;
}

int main(void){
  // Make hashtable
  hashtable_t *hp = hopen(10);

  // Make peoples, me and my amazing friends :)
  person_t *person1 = make_person("Sudharsan", 18); // Awesome Person

  if(hsearch(hp, searchByName, (const char *)person1->name, sizeof(person1->name)) != NULL){
    printf("Failure: No one should exist\n");
    exit(EXIT_FAILURE);
  }

	hclose(hp);
	free(person1);
	
  printf("testhSearchEmpty Succeeded!\n");
  exit(EXIT_SUCCESS);

}
