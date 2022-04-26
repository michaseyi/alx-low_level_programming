#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head node of the list
 * @idx: Index of the list where the new node should be added
 * @n: Value of the node to be added
 * Return: The address of the new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current = *head, *new_node, *ret_val = NULL, *temp;
	unsigned int i = 0;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (ret_val);
	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		ret_val = new_node;
	}
	else
	{
		while (current)
		{
			if (i + 1 == idx)
			{
				temp = current->next;
				current->next = new_node;
				new_node->next = temp;
				ret_val = new_node;
				break;
			}
			i++;
			current = current->next;
		}
	}
	return (ret_val);
}
