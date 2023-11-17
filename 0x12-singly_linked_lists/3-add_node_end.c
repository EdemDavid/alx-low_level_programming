#include "lists.h"

/**
 * add_node_end - Adds new node at end of list
 * @head: Link head
 * @str: String stored in list
 * Return: New element address or NULL if failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_node, *c_node;
	size_t a;

	n_node = malloc(sizeof(list_t));
	if (n_node == NULL)
		return (NULL);

	n_node->str = strdup(str);

	for (a = 0; str[a]; a++)
		;

	n_node->len = a;
	n_node->next = NULL;
	c_node = *head;

	if (c_node == NULL)
	{
		*head = n_node;
	}
	else
	{
		while (c_node->next != NULL)
			c_node = c_node->next;
		c_node->next = n_node;
	}

	return (*head);
}
