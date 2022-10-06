#include "search_algos.h"
#include <stdio.h>

/**
 * _interpolation_search- Performs interpolation search on a list  of
 * integers to find
 * the index of a number
 * @array: is the array to be searched
 * @start: is the index of the first item in the array
 * @end: is the index of the last item in the array
 * @value: is the value to be searched for
 * Return: is the index of value if found else -1
 */
int _interpolation_search(int *array, int start, int end, int value)
{
	int probe;

	probe = start + (int)(((double)(end - start) /
						   (array[end] - array[start])) *
						  (value - array[start]));
	if (probe > end)
	{
		printf("Value checked array[%d] is out of range\n", probe);
		return (-1);
	}
	else
	{
		printf("Value checked array[%d] = [%d]\n", probe, array[probe]);
	}
	if (array[probe] == value)
	{
		return (probe);
	}
	else if (array[probe] > value)
		return (_interpolation_search(array, start, probe - 1, value));
	else
		return (_interpolation_search(array, probe + 1, end, value));
}

/**
 * interpolation_search - Performs interpolation search on a list  of integers
 * to find the index of a number
 * @array: is the array to be searched
 * @size: is the size of the array
 * @value: is the value to be searched for
 * Return: is the index of value if found else -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (_interpolation_search(array, 0, (signed int)size - 1, value));
}
