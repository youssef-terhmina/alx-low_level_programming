#include "lists.h"

/**
 * add_nodeint - adds a node to the head
 * @head: pointer to 1st node
 * @n: value of new node
 *
 * Return: pointer to the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_h = malloc(sizeof(listint_t));

	if (!head || !new_h)
		return (NULL);

	new_h->next = NULL;
	new_h->n = n;
	if (*head)
		new_h->next = *head;
	*head = new_h;
	return (new_h);
}
