#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of s2 to concatenate with s1
 * Return: pointer to concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, total, i, j;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = strlen(s1);
	len2 = n > strlen(s2) ? strlen(s2) : n;
	total = len1 + len2 + 1;
	str = malloc(sizeof(char) * total);
	if (str == NULL)
		return (NULL);
	for (i = 0,  j = 0; j < len1; j++, i++)
	{
		str[i] = s1[j];
	}

	for (j = 0; j < len2; j++, i++)
	{
		str[i] = s2[j];
	}
	str[i] = '\0';
	return (str);
}
