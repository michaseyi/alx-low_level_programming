#include "search_algos.h"
#include <math.h>
#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * advance - advances a pointer forward
 * @current: is the pointer to advance
 * @count: is how much to advance by
 * Return: is a pointer to the new location of NULL if the end
 * was reached
 */
listint_t *advance(listint_t *current, size_t count)
{
	while (count)
	{
		if (!current->next)
		{
			current->index++;
			break;
		}
		current = current->next;
		count--;
	}
	return (current);
}

/**
 * jump_list - searches for a value in sorted list of integers using the jump
 * search algorithm
 * @list: is a pointer to the  head of the list to search in
 * @size: is the number of nodes  in list
 * @value: is the value to search for
 * Return: is a pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_size = (size_t)sqrt(size);
	listint_t *start = list, *end = advance(list, jump_size);

	if (!list)
		return (NULL);
	while (start->index < size)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   MIN(size - 1, end->index), end->n);
		if (end->index >= size || end->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				   start->index, MIN(end->index, size - 1));
			if (end->index > size - 1)
			{
				end->index = size - 1;
				end = NULL;
			}
			while (1)
			{
				if (!start)
					return (NULL);
				printf("Value checked at index [%lu] = [%d]\n", start->index, start->n);
				if (start->n == value)
					return (start);
				if (start == end)
				{
					return (NULL);
				}
				start = start->next;
			}
		}
		start = advance(start, jump_size);
		end = advance(end, jump_size);
	}
	return (NULL);
}
