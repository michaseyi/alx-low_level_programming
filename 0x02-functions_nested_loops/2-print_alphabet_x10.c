#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 * Description : prints out all letters in the alphabet 10 times
 * Return: (void)
 */

void print_alphabet_x10(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		int i;

		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
