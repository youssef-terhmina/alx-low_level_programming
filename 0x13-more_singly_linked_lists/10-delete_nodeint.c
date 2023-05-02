#include "lists.h"

/**
 * delete_nodeint_at_index - deletes node at the given index
 * @head: address of pointer to 1st node
 * @index: index of the node to delete
 *
 * Return: 1 if succeed, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *node, *prev_n;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_n->next = node->next;
			free(node);
			return (1);
		}
		i++;
		prev_n = node;
		node = node->next;
	}
	return (-1);
}
