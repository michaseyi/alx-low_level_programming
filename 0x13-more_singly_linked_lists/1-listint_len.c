#include "lists.h"

/**
 * listint_len - Gets the number of elements in a linked listint_t list.
 * @h: Head node of the list
 * Return: Number of elemets in the a linked listint_t list
 */

size_t listint_len(const listint_t *h)
{
	const listint_t *current = h;
	size_t i = 0;

	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
