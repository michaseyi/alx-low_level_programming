#include <stdlib.h>
#include "main.h"
#include <stdio.h>

int _strlen(char *s);

/**
 * _strlen - returns length of a string
 * @s: Pointer to the string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}

void _strcpy(char *dest, char *src);

/**
 * _strcpy - copy source to dest
 * @dest: destination string
 * @src: source string
 * Return: void
 */

void _strcpy(char *dest, char *src)
{
	int i, j = _strlen(src);

	for (i = 0; i < j; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void _print(char *str);

/**
 * _print - prints out a string
 * @str: input string
 * Return: void
 */

void _print(char *str)
{
	int i = 0;

	while (i < (int)_strlen(str))
	{
		putchar(str[i]);
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
	int size = _strlen(num) + 1 + numZero, i = _strlen(num), j = size, carry = 0;
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
	_strcpy(res2, res + 1);
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
	int temp = 0, sum, l1 = _strlen(n1) - 1, l2 = _strlen(n2) - 1, s, s2;
	char *r, *r2;

	s = l1 > l2 ? l1 + 2 : l2 + 2;
	s2 = s;
	r = malloc(sizeof(char) * (s + 1));
	if (r == NULL)
	{
		if (_strlen(n1))
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
	if (_strlen(n1))
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
	_strcpy(r2, r + 1);
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

	for (i = 0; i < (int)_strlen(str); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			_print("Error");
			putchar(10);
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
		_print("Error");
		putchar(10);
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];

	is_number(num1);
	is_number(num2);
	len1 = _strlen(num1);
	while (--len1 >= 0)
	{
		multResult = mul(num2, num1[len1], i++);
		if (multResult == NULL)
		{
			if (_strlen(result))
				free(result);
			exit(98);
		}
		result = add(result, multResult);
		if (result == NULL)
		{
			free(multResult);
			exit(98);
		}
		free(multResult);
	}

	_print(iterateZero(result));
	putchar(10);
	free(result);
	return (0);
}
