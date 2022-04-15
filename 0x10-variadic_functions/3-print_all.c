#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: a string that holds the list of arguments to the function
 */

void print_all(const char * const format, ...)
{
	int i = 0, j;
	operation ops[] = {{'c', print_c}, {'i', print_i}, {'f', print_f},
		{'s', print_s}};
	va_list list;
	char *space = "";

	va_start(list, format);
	while (format && format[i] != 0)
	{
		j = 0;
		while (j < 4 && ops[j].name != format[i])
			j++;
		if (j < 4)
		{
			printf("%s", space);
			ops[j].f(list);
			space = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(list);
}

/**
 * print_i - prints an integer
 * @list: valist
 */

void print_i(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_s - prints a string
 * @list: va_list
 */

void print_s(va_list list)
{
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_f - prints a float
 * @list: va_list
 */

void print_f(va_list list)
{
	printf("%f", (float)va_arg(list, double));
}

/**
 * print_c - prints a character
 * @list: va_list
 */

void print_c(va_list list)
{
	printf("%c", va_arg(list, int));
}

