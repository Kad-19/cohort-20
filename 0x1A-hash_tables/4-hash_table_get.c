#include "hash_tables.h"
/**
 * hash_table_get - gets a value from a hash tabel
 * @ht: the hash table
 * @key: the key
 * Return: the value associated with the key or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	hash_node_t *node = ht->array[index];

	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (strcmp(key, node->key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
