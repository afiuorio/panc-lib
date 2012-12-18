/*
 * strcmp.c
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

int strcmp(const char *cs, const char *ct){
	unsigned int i;

	for( i = 0; cs[i] == ct[i] && cs[i] != '\0'; i++);

	return cs[i] - ct[i];
}
