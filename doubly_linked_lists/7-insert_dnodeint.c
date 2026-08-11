#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at a given index
 * @h: Address of the pointer to the first node
 * @idx: Index where the new node should be inserted
 * @n: Integer to store in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
	unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;

	for (i = 1; i < idx && current != NULL; i++)
		current = current->next;

	if (current == NULL)
		return (NULL);

	if (current->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = current;
	new->next = current->next;
	current->next->prev = new;
	current->next = new;

	return (new);
}
