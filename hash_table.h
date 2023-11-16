#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "memory.h"

struct AddressSizePair {
  void *key;
  size_t value;
  bool tombstone;
};

struct HashTable {
  struct AddressSizePair *addresses;
  int capacity;
};

void hash_table_init(struct HashTable *ht, int capacity);

void hash_table_insert(struct HashTable *ht, struct AddressSizePair address);

struct AddressSizePair *hash_table_search(struct HashTable *ht, void *address);

void hash_table_remove(struct HashTable *ht, void *address);

#endif  // HASH_TABLE_H
