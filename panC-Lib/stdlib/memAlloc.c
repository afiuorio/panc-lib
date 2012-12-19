/*
 * memAlloc.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

#include <windows.h>
#include "stdlib.h"



struct __memoryChunck{
	struct __memoryChunck *next;
	unsigned int size;
	void *data;
	unsigned int free;
};

struct __memoryChunck *poolChunck = NULL;

#define BASEALLOC 4096



void *splitChunck(struct __memoryChunck *c, unsigned int requestByte){
	struct __memoryChunck *new;
	new = c->data + requestByte;

	new->free = 1;
	new->next = c->next;
	new->data = (void *)new + sizeof(struct __memoryChunck);
	new->size = c->size - requestByte - sizeof(struct __memoryChunck);

	c->next = new;
	c->size = requestByte;
	c->free = 0;

	return c->data;
}

void *requireNewChunck(){
	 struct __memoryChunck *new;
	 new = (struct __memoryChunck *) HeapAlloc(GetProcessHeap(), 0, BASEALLOC);
	 if( new == NULL)
		 return NULL;
	 new->data = (void *)new + sizeof(struct __memoryChunck);
	 new->size = BASEALLOC - sizeof(struct __memoryChunck);
	 new->free = 1;
	 new->next = NULL;

	 return new;
}

void *malloc(size_t size){
	struct __memoryChunck *p , *prec;

	if(size > BASEALLOC){
		p = HeapAlloc(GetProcessHeap(), 0, size);
		p->next = NULL;
		p->size = size;
		p->free = 0;
		p->data = (void *)p + sizeof(struct __memoryChunck);
		return p->data;
	}

	p = poolChunck;

	if(p == NULL){
		p = requireNewChunck();
		if(p == NULL)
			return NULL;
		poolChunck = p;
	}

	while(1){
		if(p == NULL){
			p = requireNewChunck();
			if(p == NULL)
				return NULL;
			prec->next = p;
		}


		if(p->size == size && p->free == 1){
			p->free = 0;
			return p->data;
		}
		else if(p->size > size && p->free ==1)
			return splitChunck(p,size);
		else{
			prec = p;
			p = p->next;
		}


	}
	return NULL;
}


