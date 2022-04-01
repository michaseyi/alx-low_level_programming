#include <stdio.h>
#include <stdlib.h>
/**
 *main-prints the minimum number of coins
 *to make change for an amount of money.
 *@argc:number of commandline arguments.
 *@argv:pointer to an array of commmand line arguments.
 *Return:0-success, non-zero-fail.
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i = 0, money = atoi(argv[1]);

		while (money > 0)
		{
			if (money >= 25)
				money -= 25;
			else if (money >= 10)
				money -= 10;
			else if (money >= 5)
				money -= 5;
			else if (money >= 2)
				money -= 2;
			else
				money--;
			i++;
		}
		printf("%d\n", i);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
};
