#include "lists.h"

/**
 * free_list - frees a list
 * @head: pointer to the head node
 *
 * Return: nothing
 */

void free_list(list_t *head)
{
	list_t *node, *next_n;

	if (!head)
		return;

	node = head;
	while (node)
	{
		next_n = node->next;
		free(node->str);
		free(node);
		node = next_n;
	}
}
