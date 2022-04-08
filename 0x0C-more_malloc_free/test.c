#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mul(char *num, char digit, int numZero)
{
	int size = strlen(num) + 1 + numZero, i = strlen(num);
	int j = size; 
	char *res2;
	char *res = malloc(sizeof(char) * (size + 1));
	int carry = 0, sum;
	res[size] = '\0';
	while (numZero > 0)
	{
		res[--size] = '0';
		numZero--;
	}

	while (--size >= 1)
	{
		sum = (digit - '0') * (num[--i] - '0') + carry;
		res[size] = (sum % 10) + '0';
		carry = sum / 10;
	}
	if(carry)
	{
		res[size] = carry + '0';
		return res;
	}
	res2 = malloc(sizeof(char) * (j));
	strcpy(res2, res + 1);
	free(res);
	return res2;

}
