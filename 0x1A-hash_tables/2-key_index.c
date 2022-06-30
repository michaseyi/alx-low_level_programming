#include "hash_tables.h"

/**
 * key_index - Gives the index of a key
 * @key: key is the key
 * @size: size is the size of the array of the hash table
 * Return: returns the index at which the key/value pair should be stored
 * in the array of the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long index;

	index = hash_djb2(key) % size;
	return (index);
}
