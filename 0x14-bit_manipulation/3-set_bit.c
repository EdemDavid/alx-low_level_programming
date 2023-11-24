#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index
 * @n: Number
 * @index: Index
 * Return: 1 if succes, -1 if fail
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int longPos;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	longPos = 1 << index;
	*n = *n | longPos;
	return (1);
}
