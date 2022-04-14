#include "variadic_functions.h"

/**
 * sum_them_all - Finds the sum of its parameters
 * @n: number of parameters
 * Return: sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i = 0;
	int sum = 0;

	if (n == 0)
		return (0);
	va_start(numbers, n);
	for (; i < n; i++)
	{
		sum += va_arg(numbers, int);
	}
	return (sum);
}
