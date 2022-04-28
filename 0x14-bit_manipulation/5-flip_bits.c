#include "main.h"

/**
 * flip_bits - Gets the number of bits you would need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: Number of bits to be flipped to get from @n to @m
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int ret_val = 0;

	while (n || m)
	{
		if ((n & 1) != (m & 1))
			ret_val++;
		n >>= 1;
		m >>= 1;
	}
	return (ret_val);
}
