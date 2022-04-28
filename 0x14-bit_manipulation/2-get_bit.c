#include "main.h"

/**
 * get_bit - Gets the value of a bit at a given index
 * @n: input number
 * @index: input index
 * Return: The value of the bit at index @index or -1 if an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int ret_val = -1;

	if (index >= sizeof(unsigned long) * 8)
		return (ret_val);
	ret_val = (int)((n >> index) & 1);
	return (ret_val);
}
