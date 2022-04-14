#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: a string that holds the list of arguments to the function
 */

void print_all(const char * const format, ...)
{
	int i = 0, j, n = 0;
	operation ops[] = {{'c', print_c}, {'i', print_i}, {'f', print_f},
		{'s', print_s}, {'\0', print_n}};
	va_list list;

	va_start(list, format);
	while (format && format[i] != 0)
	{
		j = 0;
		while (j < 4 && ops[j].name != format[i])
			j++;
		if (n != 0 && ops[j].name)
			printf(", ");
		ops[j].f(list, &n);
		i++;
	}
	printf("\n");
	va_end(list);
}

/**
 * print_i - prints an integer
 * @list: valist
 * @n: pointer to number of printed arguments
 */

void print_i(va_list list, int *n)
{
	(*n)++;
	printf("%d", va_arg(list, int));
}

/**
 * print_n - prints nothing
 * @l: valist
 * @n: pointer to number of printed arguments
 */

void print_n(va_list l __attribute__((unused)), int *n __attribute__((unused)))
{
}
/**
 * print_s - prints a string
 * @list: va_list
 * @n: pointer to number of printed argumets
 */

void print_s(va_list list, int *n)
{
	char *str;

	(*n)++;
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
 * @n: pointer to number of printed arguments
 */

void print_f(va_list list, int *n)
{
	(*n)++;
	printf("%f", (float)va_arg(list, double));
}

/**
 * print_c - prints a character
 * @list: va_list
 * @n: pointer to number of printed arguments
 */

void print_c(va_list list, int *n)
{
	(*n)++;
	printf("%c", va_arg(list, int));
}

