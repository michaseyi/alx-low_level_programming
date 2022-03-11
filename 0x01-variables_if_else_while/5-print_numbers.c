#include <stdio.h>

/**
 * main -Entry point
 * Description: prints allsingle digit numbers of
 * base 10 from 0
 * Return: 0
 */

int main(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		putchar(i);
	}
	putchar(10);
	return (0);
}
