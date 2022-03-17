/**
 * _isupper - Entry point
 * Description : checks if a character is upper or lowercase
 * @c: input character
 * Return: 1 if uppercase otherwise 0
 */

int _isupper(int c)
{
	int i;

	for (i = 'A', i <= 'Z', i++)
	{
		if (i == c)
		{
			return (1);
		}
	}
	return (0);
}
