#include <string.h>
#include <stdlib.h>

/**
 * _strdup - dupliates a string
 * @str: string to be duplicated
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < strlen(str); i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
