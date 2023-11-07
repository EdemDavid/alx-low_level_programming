#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Function to print a struct dog
 * @d: Pointer to denote struct type
 * Return: Void data type
 */

void print_dog(struct dog *d)
{
	if (d)
	{
		if (d->name == NULL)
			printf("Name: (nil)\n");
		else
			printf("Name: %s\n", d->name);

		printf("Age: %f\n", d->age);

		if (d->owner == NULL)
			printf("Owner: (nil)\n");

		else
		printf("Owner: %s\n", d->owner);
	}
}

