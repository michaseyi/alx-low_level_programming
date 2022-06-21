#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Prints out password generated from the given username
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 1 if argc is not 2 else 0
 */

int main(int argc, char *argv[])
{
	char passcode[7] = {0}, *gen;
	int len, i, temp;

	gen = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	if (argc != 2)
		return (1);
	len = strlen(argv[1]),
	temp = (len ^ 59) & 63;
	passcode[0] = gen[temp];
	temp = 0;
	for (i = 0; i < len; i++)
		temp += argv[1][i];
	passcode[1] = gen[(temp ^ 79) & 63];
	temp = 1;
	for (i = 0; i < len; i++)
		temp *= argv[1][i];
	passcode[2] = gen[(temp ^ 85) & 63];
	temp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	passcode[3] = gen[rand() & 63];
	temp = 0;
	for (i = 0; i < len; i++)
		temp += (argv[1][i] * argv[1][i]);
	passcode[4] = gen[(temp ^ 239) & 63];
	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	passcode[5] = gen[(temp ^ 229) & 63];
	printf("%s", passcode);
	return (0);
}
