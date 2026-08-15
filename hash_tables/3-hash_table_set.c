#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in a hash table
 * @ht: Pointer to the hash table
 * @key: Key associated with the value
 * @value: Value associated with the key
 *
 * Return: 1 on success, or 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key,
	const char *value)
{
	unsigned long int index;
	hash_node_t *node;
	hash_node_t *new_node;
	char *new_value;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return (0);

	if (key == NULL || key[0] == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);

			free(node->value);
			node->value = new_value;

			return (1);
		}

		node = node->next;
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
