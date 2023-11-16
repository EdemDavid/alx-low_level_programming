#include "lists.h"

/**
 * list_len - Indicates number of list elements
 * @h: List with elements to be returned
 * Return: Elements number
 */

size_t list_len(const list_t *h)
{
	size_t elCount = 0;

	while (h)
	{
		h = h->next;
		elCount++;
	}

	return (elCount);
}
