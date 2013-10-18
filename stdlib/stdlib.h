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

#ifndef STDLIB_H_
#define STDLIB_H_

#define RAND_MAX 32768
#define	EXIT_SUCCESS	0
#define	EXIT_FAILURE	1
#define NULL 0

#ifndef SIZE_T_DEF
#define size_t unsigned int
#define SIZE_T_DEF
#endif

void srand(unsigned int seed);
int rand();
long labs(long n);
int abs(int n);
void *bsearch(const void *key, const void *base, size_t n, size_t size, int(*cmp)(const void *keyval,const void *datum) );


void *malloc( size_t size);
void *realloc (void *p, size_t size);

void qsort(void *base, size_t n, size_t size, int(*cmp)(const void *,const void *));

#endif /* STDLIB_H_ */
