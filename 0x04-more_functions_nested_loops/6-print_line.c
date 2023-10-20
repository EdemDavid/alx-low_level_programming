#include "main.h"

/**
 * print_line - Draws a straight line in the terminal
 *
 * @n: Number of times
 *
 * Return: Always 0
 */

void print_line(int n)
{
	int x;

	for (x = 0; x < n; x++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
