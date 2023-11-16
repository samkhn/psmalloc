#include "memory.h"

#include "hash_table.h"

static struct HashTable Psaddrsizemap;

void *psmalloc(size_t size) {
  if (!Psaddrsizemap.capacity) {
    hash_table_init(&Psaddrsizemap, 10);
  }
  void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  struct AddressSizePair size_record = {addr, size, 0};
  hash_table_insert(&Psaddrsizemap, size_record);
  return addr;
}

void psfree(void *ptr) {
  struct AddressSizePair *s = hash_table_search(&Psaddrsizemap, ptr);
  if (s) {
    munmap(ptr, s->value);
    hash_table_remove(&Psaddrsizemap, ptr);
  }
}
