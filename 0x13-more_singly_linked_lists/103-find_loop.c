#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: Head node of the linked list
 * Return: The address where the loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

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
			return (slow);
		}
	}
	return (NULL);
}
