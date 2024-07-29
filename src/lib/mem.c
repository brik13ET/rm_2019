#include "lib/mem.h"
#include "lb/types.h"

void* heap __attribute__((section(".bss"));

typedef struct mem_s{
	void* 	base;
	u4		limit;
} mem;

void*	alloc	(u4 size){
	
}

void	free	(void* addr){

}
