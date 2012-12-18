
#include <stdio.h>
#include "stdlib.h"
#include "string.h"



int main(void) {

	char *string1 = "cassaforte";
	char *string2 = "cassa";
	char *string3 = "casa";
	char *string4 =" bagno";



	printf("%d\n", strcmp(string1,string2));
	printf("%d\n", strcmp(string2,string2));
	printf("%d\n", strcmp(string4,string3));
	printf("%d\n", strcmp(string1,string3));

	return 0;
}


