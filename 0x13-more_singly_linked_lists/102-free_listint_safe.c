#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list
 * @h: Pointer to the head node of a  listint_t linked list
 * Return: Size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *current;
	const listint_t *loop = NULL, *loop_addr = get_loop(*h);
	size_t ret_val = 0;

	if (h == NULL)
		return (ret_val);
	current = *h;
	while (current != loop)
	{
		if (current == loop_addr)
			loop = loop_addr;
		next = current->next;
		free(current);
		current = next;
		ret_val++;
	}
	*h = NULL;
	return (ret_val);
}
