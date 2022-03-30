#include "main.h"

/**
 * _print_rev_recursion - prints in reverse
 * @s: string to be printed
 * Return: void
 */

void _print_rev_recursion(char *s)
{
	if (!*s)
		return;
	if (*(s + 1))
		_print_rev_recursion(s + 1);
	_putchar(*s);
}
