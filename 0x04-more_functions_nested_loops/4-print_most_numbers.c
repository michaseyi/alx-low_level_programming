#include "main.h"

/**
 * print_most_numbers - prints out No from 1 - 9 execpt
 * 2 and 4
 * Return: void
 */

void print_most_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		if (i == '4' || i == '2)
			continue;
		_putchar(i);
	}
	_putchar('\n');
}
