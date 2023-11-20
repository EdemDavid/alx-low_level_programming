#include "lists.h"

/**
 * print_listint - Prints all list elements
 * @h: Pointer to list head
 * Return: Number of nodes in the list
 */

size_t print_listint(const listint_t *h)
{
	size_t nodeNum = 0;

	while (h)
	{
		nodeNum++;
		printf("%d\n", h->n);
		h = h->next;
	}

	return (nodeNum);
}
