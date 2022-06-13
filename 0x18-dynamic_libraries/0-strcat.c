#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest string
 */

char *_strcat(char *dest, char *src)
{
	int j, i = 0;

	while (1)
	{
		if (dest[i] == '\0')
		{
			j = 0;
			while (src[j])
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
