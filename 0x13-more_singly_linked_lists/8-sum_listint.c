#include "lists.h"

/**
 * sum_listint - Sums all the data(n) of a listint_t linked list
 * @head: Head node of the list
 * Return: Sum of all the data(n) of a listint_t list or 0 if list
 * is empty
 */

int sum_listint(listint_t *head)
{
	listint_t *current = head;
	int ret_val = 0;

	while (current)
	{
		ret_val += current->n;
		current = current->next;
	}
	return (ret_val);
}
