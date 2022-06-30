#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: Hash table to be inserted to or updated
 * @key: key is the key
 * @value: value is the value associated with the key
 * Return: 1 if it succeeds else 0
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *entry, *current;

	if (ht == NULL || ht->size == 0 || key == NULL || value == NULL ||
		 strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	/* Checks if key already exists to perform updates */
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			break;
		current = current->next;
	}

	if (current == NULL)
	{
		entry = malloc(sizeof(hash_node_t));
		if (entry == NULL)
			return (0);
		entry->key = strdup(key);		/* Handle malloc failure here */
		entry->value = strdup(value); /* Handle malloc failure here */
		entry->next = ht->array[index] == NULL ? NULL : ht->array[index];
		ht->array[index] = entry;
	}
	else
	{
		free(current->value);
		current->value = strdup(value); /* Handle malloc failure here */
	}
	return (1);
}
