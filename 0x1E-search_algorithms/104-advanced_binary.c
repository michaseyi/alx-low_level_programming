
#include "search_algos.h"
#include <stdio.h>

int _advanced_binary(int *, int, int, int);
void print(int *, int, int);
/**
 * advanced_binary- Performs binary search on a list  of integers to find
 * the index of a number
 * @array: is the array to be searched
 * @size: is the number of items in the array to be searched
 * @value: is the value to be searched for
 * Return: is the index of value if found else -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (_advanced_binary(array, 0, (signed int)size - 1, value));
}

/**
 * _advanced_binary - Performs binary search on a list  of integers to find
 * the index of a number
 * @array: is the array to be searched
 * @start: is the index of the first item in the array
 * @end: is the index of the last item in the array
 * @value: is the value to be searched for
 * Return: is the index of value if found else -1
 */
int _advanced_binary(int *array, int start, int end, int value)
{
	int mid = ((end - start) / 2) + start;

	if (start > end)
		return (-1);
	print(array, start, end);
	if (array[mid] == value)
	{
		if (mid > 0 && array[mid - 1] == value)
			return (_advanced_binary(array, start, mid, value));
		return (mid);
	}
	else if (array[mid] > value)
		return (_advanced_binary(array, start, mid - 1, value));
	else
		return (_advanced_binary(array, mid + 1, end, value));
}
/**
 * print - prints out an array
 * @array: is the array to be printed
 * @start: is the index of the first item
 * @end: is the index of the last item
 */
void print(int *array, int start, int end)
{
	printf("Searching in array: ");
	while (start <= end)
	{
		if (start == end)
		{
			printf("%d\n", array[start++]);
			break;
		}
		printf("%d, ", array[start++]);
	}
}
