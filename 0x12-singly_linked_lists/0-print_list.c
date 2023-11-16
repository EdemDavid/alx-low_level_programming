#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_list - prints elements of a list
 * @h: list with elements to be printed
 * Return: Number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t nodesnum = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		else
			printf("[%d] %s\n", h->len, h->str);

		nodesnum++;
		h = h->next;
	}

	return (nodesnum);
}
