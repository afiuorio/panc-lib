/*
 * strcat.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

char *strcat(char *s, const char *ct){
	char *dest = s;
	char *mitt = ct;
	while( *dest++ != '\0' );
	dest--;
	while( *dest++ = *mitt++);

	return s;
}
