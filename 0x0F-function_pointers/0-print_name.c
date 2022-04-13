#include "function_pointers.h"

/**
 * print_name - Prints a name
 * @name: The name to be printed
 * @f: Pointer to a function that prints a name
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (f == NULL || name == NULL)
		return;
	f(name);
}
