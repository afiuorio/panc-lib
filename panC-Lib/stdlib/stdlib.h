/*
 * stdlib.h
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
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

#endif /* STDLIB_H_ */
