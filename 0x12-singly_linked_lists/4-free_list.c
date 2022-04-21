#include "lists.h"
#include <stdlib.h>

/**
 * free_list - Frees a list_t list
 * @head: Head of the list
 */

void free_list(list_t *head)
{
	if (head && head->next != NULL)
		free_list(head->next);
	if (head != NULL)
	{
		free(head->str);
		free(head);
	}
}
