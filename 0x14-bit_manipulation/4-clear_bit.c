#include "main.h"

unsigned long int raise_pow_long(int base, unsigned int power);

/**
 * raise_pow_long - Raises @base to power of @power
 * @base: base number
 * @power: power
 * Return: @base raised to power @power
 */

unsigned long int raise_pow_long(int base, unsigned int power)
{
	unsigned long int ret_val = 1;

	while (power)
	{
		ret_val *= base;
		power--;
	}
	return (ret_val);
}

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: input number
 * @index: position to set bit
 * Return: 1 if it worked or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	int ret_val = -1;
	unsigned long pos_value;

	if (index >= (unsigned int)sizeof(unsigned long) * 8)
		return (ret_val);

	pos_value = raise_pow_long(2, index);
	if (((*n) >> index) & 1)
		*n = (*n) ^ pos_value;
	ret_val = 1;
	return (ret_val);
}

