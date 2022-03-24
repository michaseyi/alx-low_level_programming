#include "main.h"
#include <string.h>

/**
 * _strncpy - copy source to dest by n amount
 * @dest: destination string
 * @src: source string
 * @n: amount to copy
 * Return: pointer to the destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j = strlen(src);

	for (i = 0; i < n; i++)
	{
		if (i < j)
			dest[i] = src[i];
		else
			dest[i] = 0;
	}
	return (dest);
}
