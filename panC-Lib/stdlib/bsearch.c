/*
 * bsearch.c
 *
 * Author: Andrea Francesco Iuorio
 * 		   Student at Computer Science, Università degli Studi di Milano
 * 		   andreafrancesco.iuorio@gmail.com
 *
 * Create on: 18/dec/2012
 */

#include"stdlib.h"
/*Search key in base, an array of n object with size n, using a binary search. The array is suppose to be
sorted with the cmp function. cmp must return a negative int if the first argument ( the key ) is less than
the second, 0 if equal and a positive number if the key is great than the second argument. Return a pointer to the key
 or NULL if the key is not present*/


void *bsearch(const void *key, const void *base, size_t n, size_t size, int(*cmp)(const void *keyval,const void *datum) )
{
	int left = 0;
	int right = n - 1;

	while(left <= right){
		int index = (right + left)>>1 ;
		void *ptr = base + (index*size);
		int val = cmp(key, ptr);

		if(val==0)
			return ptr;
		else if(val < 0)
			right = index - 1;
		else
			left = index + 1;
	}
	return 0;
}
