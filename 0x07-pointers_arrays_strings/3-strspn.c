#include <main.h>

/**
 * _strspn - gets number of bytes in the initial segment of s which
 * consist only of byts from accept
 * @s: input string
 * @accept: input string
 * Return: number of bytes matched
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int wordCount = 0;
	int i = 0, isPresent, j;

	while (1)
	{
		j = 0;
		isPresent = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				wordCount++;
				isPresent = 1;
				break;
			}
			j++;
		}
		if (!isPresent)
			break;
		i++;
	}
	return (wordCount);
}
