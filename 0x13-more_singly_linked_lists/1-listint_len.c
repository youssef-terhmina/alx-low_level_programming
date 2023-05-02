#include "lists.h"

/**
 * listint_len - prints a linked list
 * @h: pointer to 1st node
 *
 * Return: size of the list
 */

size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
