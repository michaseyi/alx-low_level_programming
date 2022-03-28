#include "main.h"
#include <stddef.h>

/**
 * _strchr - checks for the occurence of character c
 * @s: string to be searched
 * @c: character to be searched for
 * Return: pointer to s if c is in s or NULL
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != c && s[i])
		i++;
	if (s[i])
	{
		return (s + i);
	}
	else
	{
		return (NULL);
	}
}
