#include "hash_tables.h"
/**
 * create_node - creates an element
 * @key: the key
 * @value: the value of the element
 * Return: a pointer to the node created
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (node == NULL)
		return (NULL);
	node->key = malloc(strlen(key) + 1);
	node->value = malloc(strlen(value) + 1);
	strcpy(node->key, key);
	strcpy(node->value, value);
	node->next = NULL;
	return (node);
}
/**
 * hash_table_set - sets a an element in the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value of the element
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *curr_node;
	unsigned long int index;

	if (ht == NULL || *key == '\n')
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	curr_node = ht->array[index];
	if (curr_node == NULL)
	{
		node = create_node(key, value);
		if (node == NULL)
			return (0);
		ht->array[index] = node;
		return (1);
	}
	else
	{
		while (curr_node != NULL)
		{
			if (strcmp(key, curr_node->key) == 0)
			{
				free(curr_node->value);
				curr_node->value = strdup(value);
				return (1);
			}
			curr_node = curr_node->next;
		}
		node = create_node(key, value);
		if (node == NULL)
			return (0);
		node->next = ht->array[index];
		ht->array[index] = node;
	}
	return (1);
}
