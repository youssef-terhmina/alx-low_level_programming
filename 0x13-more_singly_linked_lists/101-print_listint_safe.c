#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _r - reallocates memory for an array of pointers
 * to  nodes of a linked list
 * @list: the old list to append
 * @size: the size of the new list
 * @new: new node to add to the list
 *
 * Return: pointer to the new list
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **new_ls;
	size_t i;

	new_ls = malloc(size * sizeof(listint_t *));
	if (new_ls == NULL)
	{
		free(list);
		exit(98);
	}
	for (i = 0; i < size - 1; i++)
		new_ls[i] = list[i];
	new_ls[i] = new;
	free(list);
	return (new_ls);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 *
 * Return: the nb of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, nb = 0;
	const listint_t **ls = NULL;

	while (head != NULL)
	{
		for (i = 0; i < nb; i++)
		{
			if (head == ls[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(ls);
				return (nb);
			}
		}
		nb++;
		ls = _r(ls, nb, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(ls);
	return (nb);
}
