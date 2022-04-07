#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers from min to max
 * @min: min
 * @max: max
 * Return: array of intergers ranging from min to max or NULL if memory
 * allocation fails
 */

int *array_range(int min, int max)
{
	int *arr, i, len;

	if (min > max)
		return (NULL);
	len = max - min + 1;
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < len; i++, min++)
	{
		arr[i] = min;
	}
	return (arr);
}
