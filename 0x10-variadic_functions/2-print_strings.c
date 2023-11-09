#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints strings
 * @separator: Pointer parameter
 * @n: parameter
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list lalist;
	unsigned int i;
	char *st;

	va_start(lalist, n);

	for (i = 0; i < n; i++)
	{
		st = va_arg(lalist, char *);

		if (st)
			printf("%s", st);
		else
			printf("(nil)");

		if (i < n - 1)
			if (separator)
				printf("%s", separator);
	}

	printf("\n");
	va_end(lalist);
}
