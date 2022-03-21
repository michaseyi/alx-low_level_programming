
/**
 * swap_int - Swaps the values of two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Return: Void
 */

void swap_int(int *a, int*b)
{
	int newValueAtB, newValueAtA;

	newValueAtB = *a;
	newValueAtA = *b;
	*a = newValueAtA;
	*b = newValueAtB;
}
