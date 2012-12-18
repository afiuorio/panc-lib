/*
 * strcat.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

#include "string.h"

char *strncat(char *s, const char *ct, size_t n){
	register int i;
	char *dest = s;

	while( *dest++ != '\0' );
		dest--;

	for(i = 0; i < n; i++){
		dest[i] = ct[i];
		if(ct[i] == '\0')
			while(i<n){
				dest[i] = '\0';
				i++;
			}
	}
	return s;
}
