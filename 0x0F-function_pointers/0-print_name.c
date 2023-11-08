#include "function_pointers.h"

/**
 * print_name - Function that prints a name
 * @name: Pointer to a character variable
 * @f: Pointer to a function that returns a void data type
 * Return: Void
 */

void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
