#include "main.h"

/**
 * _puts_recursion - prints out a string
 * @s: string to be printed
 * Result: void
 */

void _puts_recursion(char *s)
{
	if (!*s)
	{
		_putchar(10);
		return;
	}
	_putchar(*s);
	return (_puts_recursion((s + 1)));
}
