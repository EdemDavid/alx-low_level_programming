#include "lists.h"

/**
 * free_listint2 - Funtion that free a list
 * @head: Pointer to head
 */

void free_listint2(listint_t **head)
{
	listint_t *freeMe;

	if (head == NULL)
		return;

	while (*head)
	{
		freeMe = (*head)->next;
		free(*head);
		*head = freeMe;
	}

	head = NULL;
}
