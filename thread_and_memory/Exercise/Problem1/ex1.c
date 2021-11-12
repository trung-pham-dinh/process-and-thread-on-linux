#include "ex1.h"

void* aligned_malloc(unsigned int size, unsigned int align) {
	unsigned long curr_brk = (unsigned long)sbrk(0);
	//printf("curr_brk: %lu, %p\n", curr_brk, (void*)curr_brk);
	unsigned long next_align = 0;
	if(curr_brk % align == 0) {
		next_align = curr_brk;
	}
	else {
		next_align = curr_brk - (curr_brk % align) + align;
	}
	//printf("next_align: %lu, %p\n", next_align, (void*)next_align);
	if(brk((void*)next_align) == -1) return NULL;
	if(sbrk(size) == (void*)-1) return NULL;

	return (void*)next_align;

	//return sbrk(0);
}

void* aligned_free(void* ptr) {
	if(brk(ptr)) return NULL;
	return (void*)-1;
}
