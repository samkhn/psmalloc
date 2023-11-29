#include "hash_table.h"

#include <assert.h>
#include <stdio.h>

int main(void)
{
	struct HashTable ht;
	// TODO: insert before init error
	hash_table_init(&ht, 5);
	struct AddressSizePair asp = { (void *)1, 10, 0 };
	hash_table_insert(&ht, asp);
	struct AddressSizePair *s = hash_table_search(&ht, (void *)1);
	assert(s != NULL);
	assert(s->key == (void *)1);
	assert(s->value == 10);
	hash_table_remove(&ht, (void *)1);
	assert(hash_table_search(&ht, (void *)1) == NULL);
	assert(hash_table_search(&ht, (void *)1) == NULL);
	return 0;
}
