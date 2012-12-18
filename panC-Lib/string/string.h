/*
 * string.h
 *
 *  Created on: 18/dic/2012
 *      Author: AndreaFrancesco
 */

#ifndef STRING_H_
#define STRING_H_

#ifndef SIZE_T_DEF
#define size_t unsigned int
#define SIZE_T_DEF
#endif

char *strcpy(char *s, const char *ct);
char *strncpy(char *s, const char *ct, size_t n);
char *strcat(char *s, const char *ct);
char *strncat(char *s, const char *ct, size_t n);
int strcmp(const char *cs, const char *ct);


#endif /* STRING_H_ */
