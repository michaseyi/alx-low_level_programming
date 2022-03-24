#include "main.h"

/**
 * reverse_array - reverses an array of intergers
 * @a: array to be reversed
 * @n: size of the array
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i, j, temp, midPoint = n / 2;

	for (i = 0, j = n - 1; i < midPoint; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

