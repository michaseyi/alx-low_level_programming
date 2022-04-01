#include "main.h"

/**
 * _strpbrk - locates first occurence of a string
 * @s: string to be searched
 * @accept: string to be found
 * Return: pointer to s or NULL if accept not present in s
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j;

	while (*(s + i))
	{
		j = 0;
		while (*(accept + j))
		{
			if (*(s + i) == *(accept + j))
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}
	return ('\0');
}
