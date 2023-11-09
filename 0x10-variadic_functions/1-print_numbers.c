#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - Prints numbers
 * @separator: Pointer parameter
 * @n: Parameter
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list lalist;
	unsigned int i;

	va_start(lalist, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(lalist, int));
		if (separator && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(lalist);
}
