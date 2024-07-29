#ifndef MEM_H
#define MEM_H

#include "lb/types.h"

void* 	heap 	__attribute__((section(".bss"));
void*	alloc	(u4);
void	free	(void*);

#endif
