#include "lists.h"

/**
 * get_loop - Checks if a loop exists in a listint_t linked list
 * @head: Head node of the listint_t linked list
 * Return: Pointer to the start of the loop or NULL if there is no loop
 */

const listint_t *get_loop(const listint_t *head)
{
	const listint_t *fast, *slow, *ret_val = NULL;

	fast = head;
	slow = head;
	
	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			ret_val = slow;
			break;
		}
	}
	return (ret_val);
}

/**
 * print_listint_safe - Prints a listint_t linked list with a loop
 * @head: Head node of the listint_t linked list
 * Return: The number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head, *loop = NULL;
	size_t i = 0;

	while (current != loop)
	{
		if (current == get_loop(head))
			loop = get_loop(head);
		i++;
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
	}
	if (loop)
		printf("-> [%p] %d\n", (void *)loop, loop->n);
	return (i);
}
