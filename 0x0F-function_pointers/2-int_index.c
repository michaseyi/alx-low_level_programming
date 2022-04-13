#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - Searches for an integer
 * @array: array to be searched
 * @size: size of the array
 * @cmp: pointer to the function to be used to compare values
 * Return: index of the found item, -1 if no elememts match, -1 if size
 * is <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);
	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}

