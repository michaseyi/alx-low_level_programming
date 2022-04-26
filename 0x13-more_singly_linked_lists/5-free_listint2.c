#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL
 * @head: Pointer to the head node of listint_t list
 * Return: Void
 */

void free_listint2(listint_t **head)
{
	free_list(*head);
	*head = NULL;
}

/**
 * free_list - Frees a listint_t list
 * @head: Head node of listint_t list
 * Return: Void
 */

void free_list(listint_t *head)
{
	if (head && head->next != NULL)
		free_list(head->next);
	if (head != NULL)
	{
		free(head);
	}
}
