#include "lists.h"

/**
 * list_len - Finds the number of elements in a linked list
 * @h: Pointer to Head Node of the linked list
 * Return: len of the linked list
 */

size_t list_len(const list_t *h)
{
	const list_t *current = h;
	size_t len = 0;

	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
