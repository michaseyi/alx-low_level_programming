
/**
 * _strlen - returns length of a string
 * @s: Pointer to the string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;
	return (length);
}
