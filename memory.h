#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

void *psmalloc(size_t size);
void psfree(void *ptr);
void *pscalloc(size_t nmemb, size_t size);

#endif