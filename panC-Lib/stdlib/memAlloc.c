/*
 * memAlloc.c
 *
 * Author: Andrea Francesco Iuorio
 * 		   Student at Computer Science, Università degli Studi di Milano
 * 		   andreafrancesco.iuorio@gmail.com
 *
 * Create on: 18/dec/2012
 */

#include <windows.h>
#include "stdlib.h"

struct __memoryChunck{
	struct __memoryChunck *next;
	unsigned int size;
	void *data;
	unsigned int free;
};

struct __memoryChunck *__poolChunck = NULL;

#define __PAGEMEMORY 4096

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

void *requireNewChunck(unsigned int numPage){
	 struct __memoryChunck *new;
	 new = (struct __memoryChunck *) HeapAlloc(GetProcessHeap(), 0, numPage*__PAGEMEMORY);
	 if( new == NULL)
		 return NULL;
	 new->data = (void *)new + sizeof(struct __memoryChunck);
	 new->size = numPage*__PAGEMEMORY - sizeof(struct __memoryChunck);
	 new->free = 1;
	 new->next = NULL;

	 return new;
}

void __initMemoryPool(){
	if(__poolChunck == NULL)
			__poolChunck = requireNewChunck(1);
}

void *malloc(size_t size){
	struct __memoryChunck *p , *prec;

	__initMemoryPool();
	p = __poolChunck;

	while(1){
		if(p == NULL){
			p = requireNewChunck( (size/__PAGEMEMORY) +1);
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

void *realloc (void *p, size_t size){
	void *ptrRet = malloc(size);
	if(ptrRet == NULL)
		return NULL;
	struct __memoryChunck *headerP = p - sizeof(struct __memoryChunck);
	headerP->free = 1;	/*TODO: Maybe i can use a free instead ?*/
	int minSize = size <= headerP->size ? size : headerP->size;
	register int i;
	for( i = 0; i < minSize; i++)	/*Not very nice, but can work*/
		((char *)ptrRet)[i] = ((char *)p)[i];
	return ptrRet;
}

/*TODO we need a better free function.*/
void free(void *p){
	struct __memoryChunck *act = p - sizeof(struct __memoryChunck);
	act->free = 1;
}

void free(void *ptr){
	struct __memoryChunck *data = ptr - sizeof(struct __memoryChunck);
	data->free = 1;
}
