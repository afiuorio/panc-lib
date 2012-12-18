/*
 * labs.c
 *
 * Author: Andrea Francesco Iuorio
 * 		   Student at Computer Science, Università degli Studi di Milano
 * 		   andreafrancesco.iuorio@gmail.com
 *
 * Create on: 18/dec/2012
 */

/*A very simple abs implementation that don' t use if statement*/

int labs(long n)
{
	int t = (unsigned int)n >> (sizeof(long)* 8 -1);
	return ( -t) ^ (n-t);
}
