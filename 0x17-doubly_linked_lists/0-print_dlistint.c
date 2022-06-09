#include "lists.h"

/**
 * print_dlistint - Prints all the element of a dlistint_t list
 * @h: Pointer to the head of the list
 * Return: The number of nodes printed
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}
	return (len);
}
