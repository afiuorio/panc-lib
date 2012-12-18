/*
 * strcpy.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

#include "string.h"
char *strncpy(char *s, const char *ct, size_t n){
	register int i;
	for(i=0; i < n; i++){
		s[i] = ct[i];
		if(s[i] == '\0')
			while(i<n){
				s[i] = '\0';
				i++;
			}
	}
	return s;
}
