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
  person_t *person2 = make_person("Taylor", 19); // Awesome Person
  person_t *person3 = make_person("James", 200); // Sometimes Awesom Person
  person_t *person4 = make_person("Ben Liu", 27); // Miss you!

  hput(hp, (void *)person1, (const char *)person1->name, sizeof(person1->name));
  hput(hp, (void *)person2, (const char *)person2->name, sizeof(person2->name));
  hput(hp, (void *)person3, (const char *)person3->name, sizeof(person3->name));
  hput(hp, (void *)person4, (const char *)person4->name, sizeof(person4->name));

  if(hsearch(hp, searchByName, (const char *)person1->name, sizeof(person1->name)) == NULL){
    printf("Failure: Could not find Sud\n");
    exit(EXIT_FAILURE);
  }
  if(hsearch(hp, searchByName, (const char *)person2->name, sizeof(person2->name)) == NULL){
    printf("Failure: Could not find Taylor\n");
    exit(EXIT_FAILURE);
  }
  if(hsearch(hp, searchByName, (const char *)person3->name, sizeof(person3->name)) == NULL){
    printf("Failure: Could not find James\n");
    exit(EXIT_FAILURE);
  }
  if(hsearch(hp, searchByName, (const char *)person4->name, sizeof(person4->name)) == NULL){
    printf("Failure: Could not find Ben\n");
    exit(EXIT_FAILURE);
  }

  printf("testhSearchNonempty Succeeded, everone was found!\n");
  exit(EXIT_SUCCESS);


}
