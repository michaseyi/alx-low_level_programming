#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: number of arguments
 * @av: array of arguments
 * Return: concatenated string
 */

char *argstostr(int ac, char **av)
{
	int i, k;
	unsigned int j;
	char *cat;

	if (ac == 0 || av == NULL)
		return (NULL);
	j = ac + 1;
	k = 0;
	for (i = 0; i < ac; i++)
		j += strlen(av[i]);
	cat = (char *)malloc(j * sizeof(char));
	if (cat == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; j < strlen(av[i]); j++, k++)
			*(cat + k) = av[i][j];
		*(cat + k) = '\n';
		k++;
	}
	*(cat + k) = '\0';
	return (cat);
}
