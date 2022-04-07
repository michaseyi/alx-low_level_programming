#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - reallocates memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: the size of allocated space of ptr
 * @new_size: the new size for new memory block
 * Return: NULL if allocation fails, NULL if new_size = 0 and ptr is not NULL
 * else returns pointer to reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;

	if (old_size == new_size)
		return (ptr);
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
			return (NULL);
		else
			return ((void *)new);
	}
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	free(ptr);
	return (new);
}
