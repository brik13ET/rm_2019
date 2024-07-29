#ifndef FMT_H
#define FMT_h
#include "lb/types.h"

extern u2	c_pos;

char*	fmt	(char*,...);
/* %c - char
 * %s - string
 * %d - int (base 10)
 * %x - int (base 16)
 * %o - int (base 8)
 * %b - int (base 2)
 */

char itos	(u4,u1);
void print	(char*);
u4   strlen	(char*);
#endif
