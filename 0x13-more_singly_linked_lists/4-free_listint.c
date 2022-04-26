#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: Head node of listint_t list
 * Return: Void
 */

void free_listint(listint_t *head)
{
	if (head && head->next != NULL)
		free_listint(head->next);
	if (head != NULL)
	{
		free(head);
	}
}
