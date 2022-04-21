#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to end head node
 * @str: Value of the new node to be added
 * Return: Address of the new node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *current = *head;

	if (*head == NULL)
	{
		new_node = malloc(sizeof(list_t));
		if (new_node == NULL)
			return (NULL);
		new_node->str = strdup(str);
		new_node->len = strlen(str);
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new_node = malloc(sizeof(list_t));
		if (new_node == NULL)
			return (NULL);
		new_node->str = strdup(str);
		new_node->len = strlen(str);
		new_node->next = NULL;
		current->next = new_node;
		return (new_node);
	}
}
