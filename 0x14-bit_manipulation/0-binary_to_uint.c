#include "main.h"

unsigned int raise_pow(int base, unsigned int power);

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 * Return: Conveted number or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i, len, ret_val = 0;

	if (b == NULL)
		return (ret_val);
	for (i = 0; b[i]; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (ret_val);
	}
	len = strlen(b);
	i = 0;
	len--;
	while (1)
	{
		ret_val += ((b[len] - '0') * raise_pow(2, i));
		if (len == 0)
			break;
		i++;
		len--;
	}
	return (ret_val);
}

/**
 * raise_pow - Raises @base to power of @power
 * @base: base number
 * @power: power
 * Return: @base raised to power @power
 */

unsigned int raise_pow(int base, unsigned int power)
{
	unsigned int ret_val = 1;

	while (power)
	{
		ret_val *= base;
		power--;
	}
	return (ret_val);
}
