#include "lists.h"

/**
 * add_nodeint - Adds new node to beginning of list
 * @head: Pointer to list head
 * @n: New node
 * Return: New element addres or NULL if fail
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;

	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = *head;

	*head = newNode;

	return (newNode);
}
