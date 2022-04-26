#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: The head node of the listint_t list.
 * Return: The number of nodes
 */

size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t i = 0;

	while (current)
	{
		i++;
		printf("%d\n", current->n);
		current = current->next;
	}
	return (i);
}
