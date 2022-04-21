#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - Adds a new node at the beginning of a list_t list
 * @head: Pointer to head node
 * @str: Value of node to be created
 * Return: Address of created node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->len = strlen(str);
	temp = *head;
	*head = new_node;
	new_node->next = temp;
	return (new_node);
}
