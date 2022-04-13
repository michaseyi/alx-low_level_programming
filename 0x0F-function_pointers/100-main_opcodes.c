#include <stdio.h>
#include <stdlib.h>


/**
 * main - Prints out the first argv[1] bytes of instructions
 * @argc: number of command line argument
 * @argv: array of pointers to command line arguments
 * Return: 0 is successful, 1 if incorrect number of argument,
 * 2 if number of bytes is negative
 */

int main(int argc, char *argv[])
{
	int n, i;
	unsigned char *ptr = (void *)main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (i = 0; i < n; i++)
	{
		printf("%02x", ptr[i]);
		if (i != n - 1)
			printf(" ");
	}
	if (n != 0)
		printf("\n");
	return (0);
}
