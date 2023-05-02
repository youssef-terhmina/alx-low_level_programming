#include "lists.h"

/**
 * add_nodeint_end - adds a node to the tail of list
 * @head: pointer to 1st node
 * @n: value of new node
 *
 * Return: pointer to the new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_n = malloc(sizeof(listint_t));
	listint_t *node;

	if (!head || !new_n)
		return (NULL);

	new_n->next = NULL;
	new_n->n = n;
	if (!*head)
		*head = new_n;
	else
	{
		node = *head;
		while (node->next)
			node = node->next;
		node->next = new_n;
	}
	return (new_n);
}
