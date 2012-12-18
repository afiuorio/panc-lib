
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include<windows.h>


int main(void) {


	void *newHeap;

	newHeap = malloc(12);
		printf("%d\n",newHeap);
		void * newHeap2 = malloc(12);
			printf("%d\n",newHeap2);
			printf("%d\n",newHeap2 - newHeap);
			newHeap = malloc(12);
			printf("%d\n",newHeap);


	return 0;
}


