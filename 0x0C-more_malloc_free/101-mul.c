#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

void _printf(char *str);

/**
 * _printf - prints out a string
 * @str: input string
 * Return: void
 */

void _printf(char *str)
{
	int i = 0;

	while (i < (int)strlen(str))
	{
		_putchar(str[i]);
		i++;
	}
}

char *mul(char *num, char digit, int numZero);

/**
 * mul - multiplies a number by a single digit and appends zeros to it
 * @num: number
 * @digit: digit
 * @numZero: number of zeroes to add
 * Return: pointer to the result or NULL if memory allocatin fails
 */

char *mul(char *num, char digit, int numZero)
{
	int size = strlen(num) + 1 + numZero, i = strlen(num), j = size, carry = 0;
	int sum;
	char *res2, *res;

	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	while (numZero > 0)
	{
		res[--size] = '0';
		numZero--;
	}
	while (--size >= 1)
	{
		sum = (digit - '0') * (num[--i] - '0') + carry;
		res[size] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry)
	{
		res[size] = carry + '0';
		return (res);
	}
	res2 = malloc(sizeof(char) * j);
	if (res2 == NULL)
	{
		free(res);
		return (NULL);
	}
	strcpy(res2, res + 1);
	free(res);
	return (res2);
}

char *add(char *n1, char *n2);

/**
 * add - Adds two number together
 * @n1: first number
 * @n2: second number
 * Return: Pointer to sum or NULL if memory allocation fails
 */

char *add(char *n1, char *n2)
{
	int temp = 0, sum, l1 = strlen(n1) - 1, l2 = strlen(n2) - 1, s, s2;
	char *r, *r2;

	s = l1 > l2 ? l1 + 2 : l2 + 2;
	s2 = s;
	r = malloc(sizeof(char) * (s + 1));
	if (r == NULL)
	{
		if (strlen(n1))
			free(n1);
		return (NULL);
	}
	r[s--] = '\0';
	while (l2 >= 0 || l1 >= 0)
	{
		if (l1 >= 0 || l1 >= 0)
		{
			sum = (n1[l1--] - '0') + (n2[l2--] - '0') + temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		} else if (l1 >= 0 && l2 < 0)
		{
			sum = (n1[l1--] - '0') + temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		} else if (l2 >= 0 && l1 < 0)
		{
			sum = (n2[l2--] - '0') + temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		}
	}
	if (strlen(n1))
		free(n1);
	if (temp)
	{
		r[s] = temp + '0';
		return (r);
	}
	r2 = malloc(sizeof(char) * s2);
	if (r2 == NULL)
	{
		free(r);
		return (NULL);
	}
	strcpy(r2, r + 1);
	free(r);
	return (r2);
}

void is_number(char *str);

/**
 * is_number - checks if a string only contains digits
 * @str: input string
 * Return: void
 */

void is_number(char *str)
{
	int i;

	for (i = 0; i < (int)strlen(str); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			_printf("Error");
			_putchar(10);
			exit(98);
		}
	}
}

char *iterateZero(char *str);

/**
 * iterateZero - get rids of execess zeroes in front of a number
 * @str: input number
 * Return: pointer to zero free str
 */

char *iterateZero(char *str)
{
	int i = 0;

	while (str[i] == '0' && str[i + 1])
		i++;

	return (str + i);
}


/**
 * main - Entry point
 * @argc: number of command line argument
 * @argv: array of command line argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *num1, *num2, *multResult, *result = "\0";
	int len1, i = 0;

	if (argc != 3)
	{
		_printf("Error");
		_putchar(10);
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];

	is_number(num1);
	is_number(num2);
	len1 = strlen(num1);
	while (--len1 >= 0)
	{
		multResult = mul(num2, num1[len1], i++);
		if (multResult == NULL)
		{
			if (strlen(result))
				free(result);
			_printf("Error");
			_putchar(10);
			exit(98);
		}
		result = add(result, multResult);
		if (result == NULL)
		{
			free(multResult);
			_printf("Error");
			_putchar(10);
			exit(98);
		}
		free(multResult);
	}

	_printf(iterateZero(result));
	_putchar(10);
	free(result);
	return (0);
}
