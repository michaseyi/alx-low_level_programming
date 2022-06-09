#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delets sthe node at index @index of a
 * dlistint_t linked list
 * @head: Pointer to the head of the linked list
 * @index: Position of node to be deleted
 * Return: 1 if it deletes the node successfully else -1
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	if (head == NULL)
		return (-1);
	current = *head;
	while (current != NULL && i != index)
	{
		i++;
		current = current->next;
	}
	if (current == NULL)
		return (-1);
	if (i == 0)
		*head = current->next;
	current->prev != NULL ? current->prev->next = current->next : NULL;
	current->next != NULL ? current->next->prev = current->prev : NULL;
	free(current);
	return (1);
}
