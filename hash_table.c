#include <stdio.h>

#include "hash_table.h"

void hash_table_init(struct HashTable *ht, int capacity)
{
	ht->capacity = capacity;
	ht->addresses = (struct AddressSizePair *)mmap(
		NULL, capacity * sizeof(struct AddressSizePair),
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	memset(ht->addresses, 0, capacity * sizeof(struct AddressSizePair));
}

void hash_table_insert(struct HashTable *ht, struct AddressSizePair address)
{
	uint64_t hash =
		((uint64_t)address.key * (uint64_t)11400954310080068983ULL) %
		ht->capacity;
	if (ht->addresses[hash].value == 0 || ht->addresses[hash].tombstone) {
		ht->addresses[hash].key = address.key;
		ht->addresses[hash].value = address.value;
		ht->addresses[hash].tombstone = false;
	} else {
		uint64_t newhash = hash;
		do {
			newhash = (newhash + 1) % ht->capacity;
		} while (ht->addresses[newhash].value != 0 || newhash != hash);
		ht->addresses[newhash].key = address.key;
		ht->addresses[newhash].value = address.value;
		ht->addresses[newhash].tombstone = false;
	}
	// TODO: resize addresses region when capcaity reached.
}

struct AddressSizePair *hash_table_search(struct HashTable *ht, void *address)
{
	uint64_t hash =
		((uint64_t)address * (uint64_t)11400954310080068983ULL) %
		ht->capacity;
	struct AddressSizePair *pair = &ht->addresses[hash];
	if (pair->key == address && !pair->tombstone) {
		return pair;
	} else {
		uint64_t newhash = hash;
		do {
			newhash = (newhash + 1) % ht->capacity;
			pair = &ht->addresses[newhash];
			if (newhash == hash)
				return NULL;
			if (pair->tombstone)
				continue;
		} while (pair->key != address);
		return pair;
	}
	return NULL;
}

void hash_table_remove(struct HashTable *ht, void *address)
{
	struct AddressSizePair *pair = hash_table_search(ht, address);
	if (pair)
		pair->tombstone = true;
	// TODO: error in case pair doesnt exist
}
