#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints number followed by a new line
 * @separator: separator
 * @n: number of integer passed
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list numbers;

	va_start(numbers, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(numbers, int));
		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	printf("\n");
}

