#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include<windows.h>


int main(void) {
register int i;

	int *newHeap = malloc(13);
	printf("%X\n",newHeap);
	newHeap = malloc(17);
		printf("%X\n",newHeap);
		newHeap[3] = 4;
		printf("%d\n",newHeap[3]);
		newHeap = malloc(13);
			printf("%X\n",newHeap);
			newHeap = malloc(30000);
						printf("%X\n",newHeap);





	return 0;
}


