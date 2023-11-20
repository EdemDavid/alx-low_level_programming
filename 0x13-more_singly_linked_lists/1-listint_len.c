#include "lists.h"

/**
 * listint_len - Returns number of elements in listint_t list
 * @h: Pointer to head of list
 * Return: Number of elements in list
 */

size_t listint_len(const listint_t *h)
{
	size_t numNodes = 0;

	while (h)
	{
		numNodes++;
		h = h->next;
	}

	return (numNodes);
}
