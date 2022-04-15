#ifndef MAIN
#define MAIN

#include <stdarg.h>
#include <stdlib.h>

typedef void (*fptr)(va_list);

/**
 * struct operation - Struct operation
 *
 * @name: The name of the operator
 * @f: The function associated
 */

typedef struct operation
{
	char name;
	fptr f;
} operation;

void print_all(const char * const format, ...);
void print_c(va_list);
void print_i(va_list);
void print_f(va_list);
void print_s(va_list);


int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *, const unsigned int, ...);
void print_strings(const char *, const unsigned int, ...);

#endif
