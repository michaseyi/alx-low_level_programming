#include "main.h"
#include <string.h>

/**
 * print_rev - Prints a string in reverse
 * @s: string to be reversed
 * Result: Void
 */

void print_rev(char *s)
{
	int length = strlen(s) - 1;

	while (length >= 0)
	{
		_putchar(s[length]);
		length--;
	}
	_putchar(10);
}
