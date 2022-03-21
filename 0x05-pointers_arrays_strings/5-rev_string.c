#include <string.h>

/**
 * rev_string - reverse a string
 * @s: string to be reversed
 * Return: void
 */

void rev_string(char *s)
{
	int length, middle, i;
	char temp;

	length = strlen(s);
	middle = length / 2;
	i = 0;

	while (middle)
	{
		temp = s[i];
		s[i] = s[length - 1 - i];
		s[length - 1 - i] = temp;
		middle--;
		i++;
	}
}



