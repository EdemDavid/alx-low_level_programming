#include "main.h"
#include <stdio.h>

/**
 * main -Entry point
 * Description: Prints 1 - 100 where
 * Fizz represents multiples of 3, Buzz multiples of 5,
 * and FizzBuzz for multiples of both
 * Return: Always 0
 */

int main(void)
{
	int x;

	for (x = 1; x <= 100; x++)
	{
		if (x % 15 == 0)
			printf("FizzBuzz");
		else if (x % 3 == 0)
			printf("Fizz");
		else if (x % 5 == 0)
			printf("Buzz");
		else
			printf("%i", x);
		if (x < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
