#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list and returns
 * the head node's data
 * @head: Pointer to head node of listint_t list
 * Return: The head nodes data or 0 if list is empty
 */

int pop_listint(listint_t **head)
{
	listint_t *current = *head, *temp;
	int ret_val;

	if (current == NULL)
		ret_val = 0;
	else
	{
		temp = current->next;
		ret_val = current->n;
		free(current);
		*head = temp;
	}
	return (ret_val);
}
