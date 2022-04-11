#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;
    my_dog.age = 2.3;
    my_dog.owner = NULL;
    print_dog(&my_dog);
    return (0);
}
