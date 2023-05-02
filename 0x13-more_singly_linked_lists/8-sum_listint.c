#include "lists.h"

/**
 * sum_listint - returns sum of the data
 * @head: pointer to 1st node
 *
 * Return: sum of data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
