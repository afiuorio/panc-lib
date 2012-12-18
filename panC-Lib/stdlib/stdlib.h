/*
 * stdlib.h
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

#ifndef STDLIB_H_
#define STDLIB_H_

#define RAND_MAX 32768

typedef unsigned int size_t;

void srand(unsigned int seed);
int rand();
int labs(long n);
int abs(int n);
void *bsearch(const void *key, const void *base, size_t n, size_t size, int(*cmp)(const void *keyval,const void *datum) );


#endif /* STDLIB_H_ */
