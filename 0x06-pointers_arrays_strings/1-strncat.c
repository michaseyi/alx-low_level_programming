#include "main.h"

/**
 * _strncat - concatenates two strings by a required amout
 * @dest: destination string
 * @src: source string
 * @n: amount to concenate
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int j, i = 0;

	while (1)
	{
		if (dest[i] == '\0')
		{
			j = 0;
			while (src[j] && j < n)
			{
				dest[i] = src[j];
				i++;
				j++;
			}
			break;
		}
		i++;
	}
	return (dest);
}
