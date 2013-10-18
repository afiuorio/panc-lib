/* The MIT License (MIT)
 * Copyright (c) 2013 Andrea Francesco Iuorio
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <windows.h>
#include "stdlib.h"

/*Memory allocation using a simple chunk linked-list first-fit allocator.
 * If there isn't a chunk enough big, the program required enough memory page for the allocation.
 *
 * Actually, the free function doesn' t release any memory, just set the free flag of a chunk. This increment fragmentation e must be resolve
 */

struct __memoryChunck{
	struct __memoryChunck *next;
	unsigned int size;
	void *data;
	unsigned int free;
};

static struct __memoryChunck *__poolChunck = NULL;

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
	int minSize = (size <= headerP->size) ? size : headerP->size;
	register int i;
	for( i = 0; i < minSize; i++)	/*Not very nice, but can work*/
		((char *)ptrRet)[i] = ((char *)p)[i];
	return ptrRet;
}

/*TODO we need a free function.*/
void free(void *p){
	struct __memoryChunck *act = p - sizeof(struct __memoryChunck);
	act->free = 1;
}
