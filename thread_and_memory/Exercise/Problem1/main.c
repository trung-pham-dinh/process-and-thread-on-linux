#include "ex1.h"
#include <stdio.h>

int main() {
	//printf("current break: %p\n", sbrk(0));
	void* addr = aligned_malloc(10,16);
	//printf("after malloc: %p\n", addr);
	return 1;
}
