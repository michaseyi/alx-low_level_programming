#include "main.h"

/**
 * _strstr - finds first occurence of needle in haystack
 * @haystack: first input
 * @needle: second input
 * Return: pointer to beginning of located string or NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j, k;

	while (haystack[i])
	{
		j = i;
		k = 0;
		while (needle[k])
		{
			if (needle[k] != haystack[j])
				break;
			if (!needle[k + 1])
				return (haystack + i);
			k++;
			j++;
		}
		i++;
	}
	return ('\0');
}
