#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *psmalloc(size_t size);
void psfree(void *ptr);
void *pscalloc(size_t nmemb, size_t size);

#endif