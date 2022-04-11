#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees memory pointer by d
 * @d: memory to be freed
 */

void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
