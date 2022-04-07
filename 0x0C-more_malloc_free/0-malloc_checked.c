#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory of size b
 * @b: size of memory to be allocated
 * Return: a void pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *space;

	space = malloc(b);
	if (space == NULL)
		exit(98);
	return (space);
}

