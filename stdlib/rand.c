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

