#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given index
 * @head: Address of the pointer to the first node
 * @index: Index of the node to delete
 *
 * Return: 1 on success, or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head,
	unsigned int index)
{
	dlistint_t *current;
	unsigned int position;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	position = 0;

	while (current != NULL && position < index)
	{
		current = current->next;
		position++;
	}

	if (current == NULL)
		return (-1);

	if (current->prev != NULL)
		current->prev->next = current->next;
	else
		*head = current->next;

	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);

	return (1);
}

