#include <stdlib.h>

/**
 * create_array - creates array of size size
 * @size: size of the array
 * @c: character to fill array
 * Return: created array or NULL of memory allocation fails
 */

char *create_array(unsigned int size, char c)
{
	char *p;
	unsigned int i;

	p = (char *)malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		p[i] = c;
	}
	p[i] = '\0';
	return (p);
}
