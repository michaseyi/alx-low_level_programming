#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * jump_search - Searches for a value in a sorted array of integers using the
 * Jump Search Algorithm
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: is the index of value if present else -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump_size = (size_t)sqrt(size);
	size_t start = 0, end = jump_size, i;

	if (!array || !size)
		return (-1);
	while (start < size)
	{
		printf("Value checked array[%lu] = [%d]\n", start, array[start]);
		if (end >= size || array[end] >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", start, end);
			end = MIN(end, size - 1);
			for (i = start; i <= end; i++)
			{
				printf("Value checked array[%lu] = [%d]\n", i, array[i]);
				if (array[i] == value)
					return ((int)i);
			}
			return (-1);
		}
		start += jump_size;
		end += jump_size;
	}
	return (-1);
}
