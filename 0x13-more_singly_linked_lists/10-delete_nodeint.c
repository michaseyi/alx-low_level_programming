#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at index index of a listint_t
 * linkde list
 * @head: Pointer to the head node of the list
 * @index: Index of the node that should be deleted
 * Return: 1 if it succeeds or -1 if it fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head, *temp;
	int ret_val = -1;
	unsigned int i = 0;


	if (current != NULL && index == 0)
	{
		temp = current->next;
		free(*head);
		*head = temp;
		ret_val = 1;
	}
	else
	{
		while (current && current->next)
		{
			if (i + 1 == index)
			{
				temp = current->next->next;
				free(current->next);
				current->next = temp;
				ret_val = 1;
				break;
			}
			i++;
			current = current->next;
		}
	}
	return (ret_val);
}
