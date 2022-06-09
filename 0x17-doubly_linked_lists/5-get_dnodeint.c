#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
 * @head: Pointer to the head of the dlistint_t linked list
 * @index: Index of the node to be gotten
 * Return: The address of the node if it exists else NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i != index)
	{
		i++;
		head = head->next;
	}
	return (head);
}
