/**
 * _pow_recursion - calculates x raised to power y
 * @x: first input
 * @y: second input
 * Return: x raised to power y
 */

int _pow_recursion(int x, int y)
{
	int res;

	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	res = x * _pow_recursion(x, y - 1);
	return (res);
}
