#include "lists.h"

/**
 * get_nodeint_at_index - Gets the nth node of a listint_t linked list.
 * @head: Head node of the linked list
 * @index: The index of the node to be retrieved
 * Return: The node or NULL if not found
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head, *ret_val = NULL;
	unsigned int i = 0;

	while (current)
	{
		if (i == index)
		{
			ret_val = current;
			break;
		}
		current = current->next;
		i++;
	}
	return (ret_val);
}
