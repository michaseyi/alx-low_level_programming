#include "main.h"

/**
 * _islower - Entry point
 * Description : checks whether a character is an uppercase or lowercase
 * @c: the integer value it receives
 * Return: 1 if character is lower and 0 if character is upper
 */

int _islower(int c)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		if (c == i)
			return (1);
	}
	return (0);
}
