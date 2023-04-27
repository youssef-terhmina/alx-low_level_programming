#include "lists.h"

/**
 * add_node_end - adds a tail node to the list
 * @head: pointer to head node adress
 * @str: string - (field of node
 *
 * Return: size of list
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_n = malloc(sizeof(list_t));
	list_t *node = *head;

	if (!head || !new_n)
		return (NULL);
	if (str)
	{
		new_n->str = strdup(str);
		if (!new_n->str)
		{
			free(new_n);
			return (NULL);
		}
		new_n->len = _strlen(new_n->str);
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_n;
	}
	else
		*head = new_n;
	return (new_n);
}
