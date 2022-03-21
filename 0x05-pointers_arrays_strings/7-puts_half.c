#include "main.h"
#include <string.h>

/**
 * puts_half - prints second half of a string
 * @str: input string
 * Return: void
 */

void puts_half(char *str)
{
	int half, length;

	length = strlen(str);
	half = length / 2;
	if (length % 2 != 0)
		half++;

	while (str[half])
	{
		_putchar(str[half]);
		half++;
	}
	_putchar(10);
}
