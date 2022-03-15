#include "main.h"
/**
 * main - Entry point
 * Description: prints "_putchar\n"
 * Return: Always 0 (success)
 */

int main(void)
{
	char str[] = "_putchar\n";
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i++]);
	}
	return (0);
}
