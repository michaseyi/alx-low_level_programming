#include "main.h"

/**
 * _puts - prints out string to stdout
 * @str: string to be printed out
 *
 * Return: Void
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar(10);
}
