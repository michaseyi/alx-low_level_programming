#include "main.h"
#include <string.h>

/**
 * pal - checks if a string is a palindrome
 * @s: string
 * @start: start
 * @end: end
 * Return: 1 if palindrome else 0
 */

int pal(char *s, int start, int end)
{
	if (start > end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (pal(s, ++start, --end));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 * Return: 1 if palindrome else 0
 */

int is_palindrome(char *s)
{
	return (pal(s, 0, strlen(s) - 1));
}
