/*
 * qsort.c
 *
 * Author: Andrea Francesco Iuorio
 * 		   Student at Computer Science, Università degli Studi di Milano
 * 		   andreafrancesco.iuorio@gmail.com
 *
 *  Created on: 22/dic/2012
 */

#include"stdlib.h"

typedef struct{
	unsigned int low;
	unsigned int high;
}__qsort_stack_node;

#define STACK_SIZE  (8 * sizeof(unsigned int))
#define PUSH(l, h)  (top->low = l, top->high = h, top++)
#define POP(l, h)   (--top, l = top->low, h = top->high)
#define STACK_NOT_EMPTY   stack < top

void swap(void *a, void *b, unsigned int size){
	register int i = 0;
	char temp, *al = a, *bl = b;
	while(i<size){
		temp = *al;
		*al = *bl;
		*bl = temp;
		al++;bl++; i++;
	}
}

#define array(i) array + (i*size)

unsigned int partition(void *array, unsigned int p, unsigned int q, int (*cmp)(const void *, const void *), unsigned int size){
	unsigned int i = p+1;
	unsigned int j = q;
	while(i<=j){
		while( cmp(array(j),array(p)) > 0) j--;
		while( cmp(array(i), array(p)) <= 0 && i<=j) i++;
		if(i<j){
			swap(array(i), array(j), size);
			i++;
			j--;
		}
	}
	swap(array(p), array(j), size);
	return j;
}

void qsort(void *base, size_t n, size_t size, int(*cmp)(const void *,const void *)){
	__qsort_stack_node *top;
	__qsort_stack_node stack[STACK_SIZE];
	top = stack;
	unsigned int p = 0, q = n-1;

	PUSH(p,q);
	while(STACK_NOT_EMPTY){
		POP(p,q);
		while(p<q){
			unsigned int l = partition(base,p,q,cmp,size);
			if( l-p < q-l){
				PUSH(l+1,q);
				q = l-1;
			}
			else{
				PUSH(p,l-1);
				p= l+1;
			}
		}
	}
}
