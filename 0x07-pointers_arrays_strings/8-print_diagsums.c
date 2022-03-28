#include <stdio.h>

/**
 * print_diagsums - prints sum of diagonals
 * @a: pointer to the table
 * @size: size of each column and row
 */

void print_diagsums(int *a, int size)
{
	int left = 0, right = 0, i, l = 0, r = size - 1;

	for (i = 0; i < size; i++)
	{
		left += *(a + ((size * i) + l));
		right += *(a + ((size * i) + r));
		l++;
		r--;
	}
	printf("%d, %d\n", left, right);
}
