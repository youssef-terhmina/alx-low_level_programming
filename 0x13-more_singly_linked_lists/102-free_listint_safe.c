#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop_fl - finds a loop in a linked list
 *
 * @head: linked list to search
 *
 * Return: the address of the node where the loop starts, and returns, NULL if no loop
 */

listint_t *find_listint_loop_fl(listint_t *head)
{
	listint_t *pt, *end;

	if (head == NULL)
		return (NULL);

	for (end = head->next; end != NULL; end = end->next)
	{
		if (end == end->next)
			return (end);
		for (pt = head; pt != end; pt = pt->next)
			if (pt == end->next)
				return (end->next);
	}
	return (NULL);
}

/**
 * free_listint_safe - frees a listint list, even if it has a loop
 *
 * @h: head of the list
 *
 * Return: the number of the nodes freed
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *loop_n;
	size_t len;
	int loop = 1;

	if (h == NULL || *h == NULL)
		return (0);

	loop_n = find_listint_loop_fl(*h);
	for (len = 0; (*h != loop_n || loop) && *h != NULL; *h = next)
	{
		len++;
		next = (*h)->next;
		if (*h == loop_n && loop)
		{
			if (loop_n == loop_n->next)
			{
				free(*h);
				break;
			}
			len++;
			next = next->next;
			free((*h)->next);
			loop = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (len);
}
