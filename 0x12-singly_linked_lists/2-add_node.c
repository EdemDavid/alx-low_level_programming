#include "lists.h"

/**
 * add_node - Adds new node at beginning of list
 * @head: Initial list
 * @str: String to be added to node
 * Return: New element address or NULL if fail
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newNode;
	int lenLength = 0;

	newNode = malloc(sizeof(list_t));
	if (newNode == NULL)
		return (NULL);

	while (str[lenLength])
		lenLength++;

	newNode->len = lenLength;
	newNode->str = strdup(str);
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
