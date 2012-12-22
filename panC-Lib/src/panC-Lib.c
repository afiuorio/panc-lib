#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include<windows.h>
#include<time.h>

#define DIM 10

int compareInt (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(void) {
register int i;

int *vector = malloc(DIM*sizeof(int));

	srand(time(NULL));
	for(i=0; i<DIM; i++){
		vector[i] = rand();
		printf("%d ",vector[i]);
	}
	printf("\n");
	qsort(vector, DIM,sizeof(int), compareInt );
	printf("\n");
	for(i=0; i <DIM; i++){
		printf("%d ",vector[i]);
	}



	return 0;
}


