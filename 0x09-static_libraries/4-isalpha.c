#include "main.h"

/**
 * _isalpha - Entry point
 * Description : tests for upper or lower case characters
 * @c: the input value it receives
 * Return: 1 for uppercase and 0 for lowercase
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
