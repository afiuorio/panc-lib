/*
 * rand.c
 *
 * Author: Andrea Francesco Iuorio
 * 		   Student at Computer Science, Università degli Studi di Milano
 * 		   andreafrancesco.iuorio@gmail.com
 *
 * Create on: 18/dec/2012
 */

/*A simple LCG ( linear congruential generator ) implementation. The algorithms determinate a pseudorandom
 * generator using the recursive formula
 *
 *  X(n+1) = (X(N) * a) + b mod N
 *
 *  X(0) is defined as the seed of the generator. ANSI C required that the seed value is initialized to 1.
 *
 * This implementation use a = 513, b = 19 and N RAND_MAX value, defined in the ANSI C as 32767.
 */

#include<stdio.h>
static unsigned int __pClib_seed = 1;

void srand(unsigned int seed)
{
	__pClib_seed = seed;
}

int rand()
{
	__pClib_seed = ( (__pClib_seed * 513) +1 ) & 0x7fff;
	return __pClib_seed;
}

