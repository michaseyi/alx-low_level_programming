#include <stdio.h>

void __attribute__((constructor)) before_main(void);

/**
 * before_main - Prints out a string before the main function is
 * executed
 */

void before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
