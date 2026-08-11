#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at a given index
 * @head: Pointer to the first node of the list
 * @index: Index of the node, starting from 0
 *
 * Return: Address of the node, or NULL if it does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head,
	unsigned int index)
{
	unsigned int position;

	position = 0;

	while (head != NULL)
	{
		if (position == index)
			return (head);

		head = head->next;
		position++;
	}

	return (NULL);
}
