#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the head of the linked list
 * @idx: Position to add new node
 * @n: Value of the new node to be added
 * Return: The address of the inserted node or NULL if it fails
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *current, *new_node, *prev = NULL;

	if (h == NULL)
		return (NULL);
	current = *h;
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;
	while (current != NULL && i != idx)
	{
		prev = current;
		current = current->next;
		i++;
	}
	if (i != idx)
	{
		free(new_node);
		return (NULL);
	}
	if (i == 0)
		*h = new_node;
	current != NULL ? current->prev = new_node : NULL;
	new_node->next = current;
	prev != NULL ? prev->next = new_node : NULL;
	new_node->prev = prev;
	return (new_node);
}
