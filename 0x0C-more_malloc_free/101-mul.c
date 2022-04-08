#include <stdlib.h>
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

void mul(char *res, char *num, char digit, int numZero);

/**
 * mul - multiplies a number by a single digit and appends zeros to it
 * @res: where to store the result
 * @num: number
 * @digit: digit
 * @numZero: number of zeroes to add
 * Return: void
 */

void mul(char *res, char *num, char digit, int numZero)
{
	int i = _strlen(num), carry = 0, size = _strlen(res) - 1;
	int sum;

	while (numZero > 0)
	{
		size--;
		numZero--;
	}
	while (i > 0)
	{
		sum = (digit - '0') * (num[--i] - '0') + carry;
		res[size--] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if (carry)
		res[size] = carry + '0';
}

void add(char *n1, char *n2);

/**
 * add - Adds two number together
 * @n1: first number
 * @n2: second number
 * Return: void
 */

void add(char *n1, char *n2)
{
	int temp = 0, sum, l1 = _strlen(n1) - 1, l2 = _strlen(n2) - 1, s = l1;

	while (l2 >= 0 || l1 >= 0)
	{
		if (l1 >= 0 || l1 >= 0)
		{
			sum = (n1[l1--] - '0') + (n2[l2--] - '0') + temp;
			temp = sum / 10;
			n1[s--] = (sum % 10) + '0';
		} else if (l1 >= 0 && l2 < 0)
		{
			sum = (n1[l1--] - '0') + temp;
			temp = sum / 10;
			n1[s--] = (sum % 10) + '0';
		} else if (l2 >= 0 && l1 < 0)
		{
			sum = (n2[l2--] - '0') + temp;
			temp = sum / 10;
			n1[s--] = (sum % 10) + '0';
		}
	}
	if (temp)
	{
		n1[s] = temp + '0';
	}
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
void init(char *str, int size);

/**
 * init - sets each charater in str to '0'
 * @str: input string
 * @size: size
 * Return: void
 */

void init(char *str, int size)
{
	int i = 0;

	for (; i < size - 1; i++)
		str[i] = '0';
}

/**
 * main - Entry point
 * @argc: number of command line argument
 * @argv: array of command line argument
 * Return: 0
 */


int main(int argc, char *argv[])
{
	char *num1, *num2, *multResult, *result;
	int len1, len2, i = 0, size;

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
	len2 = _strlen(num2);
	size = len1 + len2 + 1;
	result = malloc(sizeof(char) * size);
	if (result == NULL)
		exit(98);
	multResult = malloc(sizeof(char) * size)
	if (multResult == NULL)
	{
		free(result);
		exit(98);
	}
	result[size - 1] = '\0';
	multResult[size - 1] = '\0';

	init(result, size);
	init(multResult, size);
	while (--len1 >= 0)
	{
		init(multResult, size);
		mul(multResult, num2, num1[len1], i++);
		add(result, multResult);
	}

	_print(iterateZero(result));
	putchar(10);
	free(multResult);
	free(result);
	return (0);
}
