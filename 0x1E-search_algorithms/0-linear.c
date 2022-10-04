#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - Searches for a value in an array of integers using the
 * Linear Searc Algorighm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: is the first index where value is located or -1 if value
 * not found or array is NULL
 */

int linear_search(int *array, size_t size, int value)
{
	int result = -1;
	size_t i;

	if (!array)
	{
		return (result);
	}
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			result = i;
			break;
		}
	}
	return (result);
}
