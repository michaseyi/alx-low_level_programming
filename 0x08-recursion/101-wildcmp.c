#include "main.h"

/**
 * position - gets the highest positoin of a in s
 * @s: string to be checked
 * @a: character to be found
 * @n: n
 * @i: i
 * Return: highest position of a in s
 */

int position(char *s, char a, int n, int i)
{
	if (!*s)
		return (i);
	if (*s == a)
		i = n;
	return (position(s + 1, a, n + 1, i));
}

/**
 * wildcmp - compares two strings with wildcard
 * @s1: first string
 * @s2: string with wild card
 * Return: 1 if s2 matches s1 else 0
 */

int wildcmp(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (*(s2 + 1) && !*s1)
			return (0);
		if (*(s2 + 1) == *s1)
			return (wildcmp(s1 + position(s1, *(s2 + 1), 0, 0), s2 + 1));
		else if (*(s2 + 1) != *(s1 + 1))
			return (wildcmp(s1 + 1, s2));
		else if (*(s2 + 1) == *(s1 + 1))
			return (wildcmp(s1 + 1, s2 + 1));
	}
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s1 != *s2)
		return (0);
}
