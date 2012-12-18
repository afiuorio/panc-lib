
#include <stdio.h>
#include "stdlib.h"

int compareInt (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(void) {
	int array[500000];
	register int i;
	for(i=0; i < 500000; i++)
		array[i] = i;

	for(i=0; i < 500000; i++) {
		int zero = i;
		int *isZero = bsearch(&zero,array, 500000, sizeof(int), compareInt) ;
		printf("%d\n",*isZero);
	}
	return 0;
}


