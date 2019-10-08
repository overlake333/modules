/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include "queue.h"
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}



typedef struct myHash_t{
  uint32_t size;
  queue_t *table;

  
} myHash_t;


static myHash_t *makeHash(uint32_t hsize){
  myHash_t *ht;
  if(!(ht = (myHash_t *)malloc(sizeof(myHash_t)))){
    return NULL;
  }

  ht->size = hsize;
  queue_t *table = malloc(hsize);


  for(int i = 0; i < hsize; i++){
    queue_t *temp = qopen();
    table[i] = temp;
  }

  ht->table = table;
  return ht;
}

hashtable_t *hopen(uint32_t hsize){
  myHash_t *ht = makeHash(hsize);
  if(ht != NULL){
    return (hashtable_t *)ht;
  }
  else{
    return NULL;
  }
}

void hclose(hashtable_t *htp){
  myHash_t *ht = (myHash_t *)htp;
	queue_t *i = (ht->table);
	
  for(int q = 0; q<ht->size; q++){
   
		

  }
  //free(ht);
}


int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen){
  myHash_t *ht = (myHash_t *)htp;
  uint32_t index = SuperFastHash(key, keylen, ht->size);

  return qput(&((*ht).table)+index, ep);
}


