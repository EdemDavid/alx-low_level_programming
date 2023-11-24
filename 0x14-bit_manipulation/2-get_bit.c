#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: Number
 * @index: Index
 * Return: The value of the bit at index or -1 in the case of an error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int d, c;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	d = 1 << index;
	c = n & d;
	if (c == d)
		return (1);
	return (0);
}
