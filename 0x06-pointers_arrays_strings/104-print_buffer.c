#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints out buffer 10 bytes on a line
 * @b: buffer to be printed
 * @size: size of the buffer
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int address = 0, i = 0, j;

	for (; i < size; i += 10)
	{
		printf("%08x: ", address + i);

		for (j = 0; j < 10; j++)
		{
			if ((i + j) < size)
				printf("%02x", *(b + i + j));
			else
				printf("  ");

			if ((j + 1) % 2 == 0)
				printf(" ");
		}
		for (j = 0; j < 10; j++)
		{
			if ((i + j) >= size)
				break;
			if ((*(b + i + j) >= '!' && *(b + i + j) <= '~') || *(b + i + j) == ' ')
				printf("%c", *(b + i + j));
			else
				printf(".");
		}
		printf("\n");
	}
	if (size <= 0)
		printf("\n");
}
