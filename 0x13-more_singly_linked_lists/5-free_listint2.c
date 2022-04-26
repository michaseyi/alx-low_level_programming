#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL
 * @head: Pointer to the head node of listint_t list
 * Return: Void
 */

void free_listint2(listint_t **head)
{
	listint_t *next, *current;

	if (head == NULL)
		return;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
