#include "lists.h"

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
