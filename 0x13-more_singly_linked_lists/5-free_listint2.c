#include "lists.h"

/**
 * free_listint2 - frees a list of inteegers
 * @head: address of pointer to 1st node
 *
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *node, *tem;

	if (!head)
		return;

	node = *head;
	while (node)
	{
		tem = node;
		node = node->next;
		free(tem);
	}
	*head = NULL;
}
