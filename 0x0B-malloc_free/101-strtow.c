#include <string.h>
#include <stdlib.h>

int numberOfWords(char *);

/**
 * numberOfWords - gets the number of words in a string
 * @word: input
 * Return: number of words
 */

int numberOfWords(char *word)
{
	int i = 0, count = 0;

	while (word[i])
	{
		if (word[i] == ' ')
		{
			i++;
			continue;
		}
		while (word[i] && word[i] != ' ')
			i++;
		count++;
	}
	return (count);
}

int allocWord(char **, char *);

/**
 * allocWord - allocates memory to pointers in words
 * @words: array of pointers
 * @str: string
 * Return: 1 if sucess else 0
 */

int allocWord(char **words, char *str)
{
	int i = 0, len, pos = 0, k;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		len = 0;
		while (str[i] && str[i] != ' ')
		{
			i++;
			len++;
		}
		words[pos] = (char *)malloc((len + 1) * sizeof(char));
		if (words[pos] == NULL)
		{
			for (k = 0; k < pos; k++)
			{
				free(words[k]);
			}
			free(words);
			return (0);
		}
		pos++;
	}
	return (1);
}

void insertWords(char **, char *);

/**
 * insertWords - inserts characters into memory location pointed by
 * *words
 * @words: array of pointers
 * @str: string
 * Return: void
 */

void insertWords(char **words, char *str)
{
	int i = 0, j = 0, k;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		k = 0;
		while (str[i] && str[i] != ' ')
		{
			words[j][k] = str[i];
			i++;
			k++;
		}
		words[j][k] = '\0';
		j++;
	}
}

/**
 * strtow - seperates a string into an array of words
 * @str: input string
 * Return: array of words or NULL if memory allocation fails
 */

char **strtow(char *str)
{
	char **words;
	int lenWords;

	if (str == NULL || !strcmp(str, ""))
		return (NULL);
	lenWords = numberOfWords(str);
	if (lenWords == 0)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (lenWords + 1));
	if (words == NULL)
		return (NULL);
	if (allocWord(words, str) == 0)
		return (NULL);
	insertWords(words, str);
	words[lenWords] = NULL;
	return (words);
}
