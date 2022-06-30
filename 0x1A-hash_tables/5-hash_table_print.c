#include "hash_tables.h"

/**
 * hash_table_print - Prints out an hash table in a key/value form
 * @ht: The hash table to be printed
 * Return: void
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *start = NULL;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		if (current != NULL)
		{
			if (start == NULL)
				start = current;
			if (current != start)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
		}
	}
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		if (current == NULL)
			continue;
		current = current->next;
		while (current != NULL)
		{
			if (start == NULL)
				start = current;
			if (current != start)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			current = current->next;
		}
	}
	printf("}\n");
}
