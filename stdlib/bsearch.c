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
