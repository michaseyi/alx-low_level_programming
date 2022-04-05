#include <stdlib.h>
#include <string.h>

/**
 * str_concat - joins to strings
 * @s1: string one
 * @s2: string two
 * Return: pointer to concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	int i, j, length;
	char *res;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	j = 0;
	length = strlen(s1) + strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * length);
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
