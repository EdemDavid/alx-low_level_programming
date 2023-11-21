#include "lists.h"

/**
 * free_listint - Funtion that frees a list
 * @head: Pointer to list head
 */

void free_listint(listint_t *head)
{
	listint_t *freeMe;

	while (head)
	{
		freeMe = head->next;
		free(head);
		head = freeMe;
	}
}
