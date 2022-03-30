#include "main.h"

/**
 * _strlen_recursion - get len of a string
 * @s: input string
 * Return: lenght of string
 */

int _strlen_recursion(char *s)
{
	int sum;

	if (!*s)
		return (0);

	sum = 1 + _strlen_recursion(s + 1);
	return (sum);
}
