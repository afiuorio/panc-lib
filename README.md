panC-Lib
========

ANSI C ( C89 ) Standard Runtime Library for Windows.

What is this project ?

This project is an implementation for the C Standard Library written specifically for the Windows operating system. Actually the implementation is not complete.

Why this project born ?

Principally for educational purpose: i love low level programming and the C Standard Library is a good example of that. There isn' t any presumption to be a real project.

What part are present in this implementation ?

You can find:

complete character function ( ctype.h )
sin and cos function ( math.h ). These function are not implemented in hardware. There aren' t any true reason for that except that i want to learn how implement in software trigonometric functions.
some string.h function ( strcat, strcmp, strcpy, strncat, strncpy )
Memory allocation using Windows heap object and some general alghoritms ( qsort, bsearch, abs, rand ) present in strlib.h.

Should i contribute to this project ?

If you want i don' t see any reason you shouldn' t. The only problem is that this project is just didattical and have no presumption to be a real-world software, so reflect before waste your time on it.
