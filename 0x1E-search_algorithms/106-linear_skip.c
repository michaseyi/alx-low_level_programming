#include "search_algos.h"
#include "math.h"
#include <stdio.h>

/**
 * advance_till_end - advances the pointer to the end of the list
 * @current: is the pointer to advance
 * Return: is the pointer to the end of the list
 */

skiplist_t *advance_till_end(skiplist_t *current)
{
	while (current->next)
		current = current->next;
	return (current);
}

/**
 * linear_skip - searches for a value in a sorted skip list of
 * integers
 * @list: is a pointer to the head of a skip list
 * @value: is the value to search for
 * Return: is a pointer to the first node with value of NULL if
 * none is found
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	while (list)
	{
		express = list->express;
		if (express)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					 express->index, express->n);
		}
		else
		{
			express = advance_till_end(list);
		}
		if (!express->next || express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					 list->index, express->index);
			while (1)
			{
				if (!list)
					return (NULL);
				printf("Value checked at index [%lu] = [%d]\n",
						 list->index, list->n);
				if (list->n == value)
					return (list);
				if (list == express)
					return (NULL);
				list = list->next;
			}
		}
		list = list->express;
	}
	return (NULL);
}
