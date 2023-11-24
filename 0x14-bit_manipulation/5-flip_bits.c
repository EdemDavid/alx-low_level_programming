#include "main.h"

/**
 * flip_bits - Returns number of flipped bits
 * @n: First number
 * @m: Second number
 * Return: Number of flipped bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, bitcount = 0;
	unsigned long int curr;
	unsigned long int excl = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		curr = excl >> a;
		if (curr & 1)
			bitcount++;
	}
	return (bitcount);
}
