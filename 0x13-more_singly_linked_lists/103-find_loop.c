#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Head node of the listint_t linked list
 * Return: The address of the node where the loop starts, or NULL if there
 * is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	return ((void *)get_loop(head));
}
