#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include<windows.h>


int main(void) {
register int i;

	int *newHeap = malloc(16);
	newHeap[3] = 4;
	printf("%X\n",newHeap);
	newHeap = realloc(newHeap,20);
	printf("%X\n",newHeap);
	printf("%d\n",newHeap[3]);







	return 0;
}


