#include "3-calc.h"

/**
 * main - Entry point
 * @argc: number of command line argument
 * @argv: array of pointers to command line argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int num1, num2;
	fptr selected_f;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	selected_f = get_op_func(argv[2]);
	if (selected_f == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	printf("%d\n", selected_f(num1, num2));
	return (0);
}
