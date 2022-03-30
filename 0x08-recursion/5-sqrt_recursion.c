#include "main.h"

/**
 * sq - prints square root
 * @n: number
 * @i: startion point
 * Return: square root of n
 */

int sq(int n, int i)
{
	if (n < 1)
		return (-1);
	if (i == n)
		return (-1);
	if ((i * i) == n)
		return (i);
	return (sq(n, i + 1));
}

/**
 * _sqrt_recursion - prints square root
 * @n: number
 * Return: square root of n
 */

int _sqrt_recursion(int n)
{
	int res = sq(n, 1);

	return (res);
}
