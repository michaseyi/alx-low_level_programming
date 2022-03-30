
/**
 * factorial - caculate factorial of a number
 * @n: input number
 * Return: factorial of n
 */

int factorial(int n)
{
	int i;

	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	i = n * factorial(n - 1);
	return (i);
}
