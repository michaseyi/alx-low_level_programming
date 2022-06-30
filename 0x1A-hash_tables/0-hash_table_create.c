#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size if the size of the underlinine array
 * Return: Returns the address or the created hash table or NULL
 * if it fails
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;
	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (hash_table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;

	return (hash_table);
}
