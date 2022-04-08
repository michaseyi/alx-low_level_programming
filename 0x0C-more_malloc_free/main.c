#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char *mul(char *num, char digit, int numZero);
char *infinite_add(char *n1, char *n2);


int main(int argc, char *argv[])
{
	char *num1 = argv[1], *num2 = argv[2];
	int len1 = strlen(num1),i = 0;
	char *multResult;
	char *result = "\0";

	while(--len1 >= 0)
	{
		multResult = mul(num2, num1[len1], i++);
		result = infinite_add(result, multResult);
		free(multResult);

	}

	printf("%s\n", result);
	free(result);
	return 0;
}
