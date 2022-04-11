#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - prints out a dog struct
 * @d: The dog struct to be printed
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name: ");
		if (d->name != NULL)
			printf("%s\n", d->name);
		else
			printf("(nil)\n");
		printf("Age: ");
		if (d->age > 0.0)
			printf("%f\n", d->age);
		else
			printf("(nil)\n");
		printf("Owner: ");
		if (d->owner != NULL)
			printf("%s\n", d->owner);
		else
			printf("(nil)\n");
	}
}

