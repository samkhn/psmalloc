#include "memory.h"

void *psmalloc(size_t size) {
  void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  return addr;
}