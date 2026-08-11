#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: Pointer to the first node of the list
 *
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
