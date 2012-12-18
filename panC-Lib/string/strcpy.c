/*
 * strcpy.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

/*Simple implementation of strcpy.*/

char *strcpy(char *s, const char *ct){
	register int i = 0;
	while(ct[i] !='\0'){
		s[i] = ct[i];
		i++;
	}
	s[i] = '\0';
	return s;
}
