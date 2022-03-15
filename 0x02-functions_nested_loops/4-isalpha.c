#include "main.h"

/**
 * _isalpha - Entry point
 * Description : tests for upper or lower case characters
 * @c: the input value it receives
 * Return: 1 for uppercase and 0 for lowercase
 */

int _isalpha(int c)
{
	int i;

	for (i = 'A'; i <= 'Z'; i++)
	{
		if (c == i)
			return (1);
	}
	return (0);
}
