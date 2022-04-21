#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all elements of a list_t
 * @h: Input data of type list_t
 * Return: number of nodes
 */

size_t print_list(const list_t *h)
{
	const list_t *current = h;
	size_t i = 0;

	while (current != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", current->len, current->str);
		current = current->next;
		i++;
	}
	return (i);
}
