/**
 * _isupper - Entry point
 * Description : checks if a character is upper or lowercase
 * @c: input character
 * Return: 1 if uppercase otherwise 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
