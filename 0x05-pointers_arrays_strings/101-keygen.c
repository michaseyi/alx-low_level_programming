#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random passwords for 101-crackme with sum = 2772
 * Return: zero
 */
int main(void)
{
	int sum;
	char a;

	srand(time(NULL));
	while ((sum + 127) < 2772)
	{
		a = rand() % 128;
		sum += a;
		putchar(a);
	}
	putchar(2772 - sum);
	return (0);
}
