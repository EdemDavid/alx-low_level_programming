#include "main.h"

/**
 * main - Determine if number is positive, negative, or zero.
 * 0: the number to be checked
 * Return: Always 0
 */

void positive_or_negative(int i)
{
	if (1 < 0)
	{
		printf("%d is %s\n", i, "negative");
	}
	else if (i > 0)
	{
		printf("%d is %s\n", i, "positive");
	}
	else
	{
		printf("%d is %s\n", i, "zero");
	}
	return;
}
