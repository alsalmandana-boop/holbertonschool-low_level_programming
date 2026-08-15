#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - initializes a store
 * @st: store to initialize
 */
void store_init(store_t *st)
{
	if (st)
		st->head = NULL;
}

/**
 * node_create - creates a new node
 * @s: session to store
 *
 * Return: pointer to new node, or NULL on failure
 */
static node_t *node_create(session_t *s)
{
	node_t *n;

	n = malloc(sizeof(*n));
	if (!n)
		return (NULL);

	n->sess = s;
	n->next = NULL;

	return (n);
}

/**
 * store_add - adds a session to the store
 * @st: store
 * @s: session to add
 *
 * Return: 1 on success, 0 on failure
 */
int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	if (!st || !s || !s->id)
		return (0);

	cur = st->head;

	while (cur)
	{
		if (cur->sess && cur->sess->id &&
		    strcmp(cur->sess->id, s->id) == 0)
		{
			session_destroy(s);
			return (0);
		}

		cur = cur->next;
	}

	n = node_create(s);
	if (!n)
	{
		session_destroy(s);
		return (0);
	}

	n->next = st->head;
	st->head = n;

	return (1);
}

/**
 * store_get - retrieves a session by id
 * @st: store
 * @id: session id
 *
 * Return: matching session, or NULL if not found
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return (NULL);

	cur = st->head;

	while (cur)
	{
		if (cur->sess && cur->sess->id &&
		    strcmp(cur->sess->id, id) == 0)
			return (cur->sess);

		cur = cur->next;
	}

	return (NULL);
}

/**
 * store_delete - removes a session from the store
 * @st: store
 * @id: id of session to delete
 * @out: optional pointer to receive removed session
 *
 * Return: 1 on success, 0 if not found
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;

	if (out)
		*out = NULL;

	if (!st || !id)
		return (0);

	prev = NULL;
	cur = st->head;

	while (cur)
	{
		if (cur->sess && cur->sess->id &&
		    strcmp(cur->sess->id, id) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;

			if (out)
				*out = cur->sess;
			else
				session_destroy(cur->sess);

			free(cur);

			return (1);
		}

		prev = cur;
		cur = cur->next;
	}

	return (0);
}

/**
 * store_destroy - destroys all sessions and nodes in the store
 * @st: store to destroy
 */
void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;

	while (cur)
	{
		next = cur->next;

		session_destroy(cur->sess);
		free(cur);

		cur = next;
	}

	st->head = NULL;
}

