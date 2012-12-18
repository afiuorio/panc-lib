
#include <stdio.h>
#include "stdlib.h"
int main(void) {
	testAbsLabs();
	return 0;
}

void testRandom()
{
	srand(10);
	register int i = 0;
	int numError = 0;
	char mapControl[32768];

	for ( i = 0; i < 32768; i++)
		mapControl[i] = 0;
	for ( i = 0; i < 32768; i++){
			int actual = rand();
			if(mapControl[actual] != 0){
				printf("Error at %d\n", actual);
				numError++;
			}
			else
				mapControl[actual] = 1;
	}
	printf("NumError = %d\n",numError);
}

void testAbsLabs(){
	signed int intA = 3;
	signed long longA= 13;

	intA = abs(intA);
	longA = labs(longA);
	printf("%d %d\n",intA,longA);
	intA = abs(intA);
	longA = labs(longA);
	printf("%d %d\n",intA,longA);


}
