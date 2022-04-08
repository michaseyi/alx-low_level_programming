#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *infinite_add(char *n1, char *n2)
{
	int temp = 0, sum, l1 = strlen(n1) - 1, l2 = strlen(n2) - 1;
	int s = l1 > l2 ? l1 + 2 : l2 + 2, s2 = s;
	char *r2, *r = malloc(sizeof(char) * (s + 1));
	r[s] = '\0';
	s--;

	while (l2 >= 0 || l1 >= 0)
	{
		if (l1 >= 0 && l2 >= 0)
		{
			sum = (n1[l1--] - '0') + (n2[l2--] - '0') +  temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		} else if (l1 >= 0 && l2 < 0)
		{
			sum = (n1[l1--] - '0') + temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		} else if (l2 >= 0 && l1 < 0)
		{
			sum = (n2[l2--] - '0') + temp;
			temp = sum / 10;
			r[s--] = (sum % 10) + '0';
		}
	}
	if (strlen(n1))
		free(n1);	
	if (temp)
	{
		r[s] = temp + '0';
		return (r);
	}
	r2 = malloc(sizeof(char) * s2);
	strcpy(r2, r + 1);
	free(r);
	return (r2);
}

