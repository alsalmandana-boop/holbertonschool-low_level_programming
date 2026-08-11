#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all data in a dlistint_t list
 * @head: Pointer to the first node of the list
 *
 * Return: Sum of all node values, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

