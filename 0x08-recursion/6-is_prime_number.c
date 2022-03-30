#include "main.h"

/**
 * prime - checks if a number is a prime number
 * @n: number
 * @i: starting point
 * Return: 1 if prime else 0
 */

int prime(int n, int i)
{
	if (n < 2)
		return (0);
	if ((i * i) >= n)
		return (1);
	if (i != n && n % i == 0)
		return (0);
	return (prime(n, i + 1));
}

/**
 * is_prime_number - checks if a number is a prime number
 * @n: number
 * Return: 1 if prime else 0
 */

int is_prime_number(int n)
{
	return (prime(n, 2));
}
