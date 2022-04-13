#ifndef _MAIN_
#define _MAIN_
#include <stdlib.h>

void print_name(char *name, void (*f)(char *));
int _putchar(char c);
void array_iterator(int *, size_t, void (*)(int));
int int_index(int *, int, int (*)(int));

#endif
