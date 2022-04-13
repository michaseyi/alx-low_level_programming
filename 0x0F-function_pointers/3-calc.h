#ifndef __MAIN__
#define __MAIN__

#include <stdio.h>
#include <stdlib.h>

/**
 * fptr - Typedef for a function pointer that returns an int and takes two
 * integers as parameters
 */

typedef int (*fptr)(int, int);

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	fptr f;
} op_t;


fptr get_op_func(char *s);
int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

#endif
