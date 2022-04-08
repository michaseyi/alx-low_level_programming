#include <stdio.h>

int main(void)
{
	char *num = "000000";
	int i = 0;

	while (num[i] == '0' && num[i + 1])
		i++;
	num = num + i;

	printf("%s\n", num);
	return 0;
}
