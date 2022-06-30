#include "hash_tables.h"
#include <string.h>

/**
 * shash_table_create - Creates a hash table
 * @size: Size if the size of the underlinine array
 * Return: Returns the address or the created hash table or NULL
 * if it fails
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_table;
	unsigned long int i;

	hash_table = malloc(sizeof(shash_table_t));
	if (hash_table == NULL)
		return (NULL);

	hash_table->size = size;
	hash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (hash_table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;
	hash_table->shead = NULL;
	hash_table->stail = NULL;

	return (hash_table);
}

/**
 * shash_table_set - Adds an element to the hash table
 * @ht: Hash table to be inserted to or updated
 * @key: key is the key
 * @value: value is the value associated with the key
 * Return: 1 if it succeeds else 0
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *entry, *current;

	if (ht == NULL || ht->size == 0 || key == NULL || value == NULL ||
		strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			break;
		current = current->next;
	}

	if (current == NULL)
	{
		entry = malloc(sizeof(shash_node_t));
		if (entry == NULL)
			return (0);
		entry->key = strdup(key);	  /* Handle malloc failure here */
		entry->value = strdup(value); /* Handle malloc failure here */
		entry->snext = NULL;
		entry->sprev = NULL;
		entry->next = ht->array[index] == NULL ? NULL : ht->array[index];
		shash_table_insert_to_sorted_list(ht, entry);
		ht->array[index] = entry;
	}
	else
	{
		free(current->value);
		current->value = strdup(value); /* Handle malloc failure here */
	}
	return (1);
}

/**
 * shash_table_insert_to_sorted_list - Insets a new entry to the sorted
 * list of the hash table
 * @ht: The hash table
 * @entry: The entry
 * Return: void
 */

void shash_table_insert_to_sorted_list(shash_table_t *ht, shash_node_t *entry)
{
	shash_node_t *current, *prev = NULL;

	current = ht->shead;
	while (current && strcmp(entry->key, current->key) > 0)
	{
		prev = current;
		current = current->snext;
	}
	if (current == ht->shead)
		ht->shead = entry;
	if (current == NULL)
		ht->stail = entry;
	entry->sprev = prev;
	entry->snext = current;
	prev != NULL ? prev->snext = entry : NULL;
	current != NULL ? current->sprev = entry : NULL;
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to be looked into
 * @key: The key of the value to be returned
 * Return: The value if found else NULL
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || ht->size == 0 || key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints out an hash table in a key/value form
 * @ht: The hash table to be printed
 * Return: void
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current, *start = NULL;

	if (ht == NULL)
		return;
	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		if (start == NULL)
			start = current;
		if (current != start)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints out an hash table in a key/value form
 * in reverse
 * @ht: The hash table to be printed
 * Return: void
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current, *start = NULL;

	if (ht == NULL)
		return;
	printf("{");
	current = ht->stail;
	while (current != NULL)
	{
		if (start == NULL)
			start = current;
		if (current != start)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes an hash table from memory
 * @ht: The hash table to be deleted
 * Return: void
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next;
		}
	}
	free(ht->array);
	free(ht);
}
