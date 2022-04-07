#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an arrsy using malloc
 * @nmemb: number of elements in the array
 * @size: size of each element in the array
 * Return: void pointer to allocated memory or NULL if allocation fails
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *space;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	space = malloc(nmemb * size);
	if (space == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
	{
		space[i] = 0;
	}
	return ((void *)space);
}
