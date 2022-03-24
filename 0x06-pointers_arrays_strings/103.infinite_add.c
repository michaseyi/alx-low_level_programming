#include <string.h>
#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: result buffer
 * @s: result length
 * Return: Addition of both numbers or 0 if r is unable
 * to store the result
 */

char *infinite_add(char *n1, char *n2, char *r, int s)
{
	int temp = 0, sum, l1 = strlen(n1) - 1, l2 = strlen(n2) - 1;

	*(r + s - 1) = '\0';
	s -= 2;

	while (l2 >= 0 || l1 >= 0)
	{
		if (s < 0)
			return (0);
		if (l1 >= 0 && l2 >= 0)
		{
			sum = (n1[l1] - '0') + (n2[l2] - '0') +  temp;
			temp = sum / 10;
			r[s] = (sum % 10) + '0';
		} else if (l1 >= 0 && l2 < 0)
		{
			sum = (n1[l1] - '0') + temp;
			temp = sum / 10;
			r[s] = (sum % 10) + '0';
		} else if (l2 >= 0 && l1 < 0)
		{
			sum = (n2[l2] - '0') + temp;
			temp = sum / 10;
			r[s] = (sum % 10) + '0';
		}
		l1--;
		l2--;
		s--;
	}
	if (s < 0 && temp)
		return (0);
	if (temp)
	{
		r[s] = temp + '0';
		return (r + s);
	}
	return (r + s + 1);
}
