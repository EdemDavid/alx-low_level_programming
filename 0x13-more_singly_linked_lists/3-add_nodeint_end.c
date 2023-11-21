#include "lists.h"

/**
 * add_nodeint_end - Adds new node at end of list
 * @head: List head pointer
 * @n: New node variable
 * Return: New node address or NULL if fail
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newNode, *tailNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (*head == NULL)
		*head = newNode;

	else
	{
		tailNode = *head;
		while (tailNode->next != NULL)
			tailNode = tailNode->next;
		tailNode->next = newNode;
	}

	return (*head);
}
