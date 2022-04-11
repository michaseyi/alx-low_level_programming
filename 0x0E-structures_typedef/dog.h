#ifndef __MAIN__
#define __MAIN__

/**
 * struct dog - Holds a dogs details
 * @name: name
 * @age: age
 * @owner: owner
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
