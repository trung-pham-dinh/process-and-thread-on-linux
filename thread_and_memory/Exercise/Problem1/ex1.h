#ifndef EXERCISE1
#define EXERICISE1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void* aligned_malloc(unsigned int size, unsigned int align);
void* aligned_free(void* ptr);

#endif
