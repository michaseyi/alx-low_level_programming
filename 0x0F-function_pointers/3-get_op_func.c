#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * described by s
 * @s: Type of operation to be performed
 * Return: Pointer to the required operation of NULL if operation not found
 */

fptr get_op_func(char *s)
{
	int i = 0;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	while (ops[i].op)
	{
		if (!strcmp(s, ops[i].op))
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
