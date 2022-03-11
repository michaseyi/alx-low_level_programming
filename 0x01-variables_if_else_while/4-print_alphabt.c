#include <stdio.h>

/**
 * main - Entry point
 * Description - prints out all alphabet in lowercase except q and e
 * Return: 0
 */

int main(void)
{
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (i == 'e' || i == 'q')
			continue;
		putchar(i);
	}
	putchar(10);
	return (0);
}
