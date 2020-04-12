#include<stdio.h>
#include"hash.h"
#include<assert.h>


typedef struct hash_node
{
	void *key;
	void *value;
	struct hash_node *prev;
	struct hash_node *next;
}hash_node_t;

struct hash
{
	unsigned int buckets;
	hashfunc_t hash_func;
	hash_node_t **nodes;
};

hash_node_t** hash_get_bucket(hash_t *hash, void *key);
hash_node_t* hash_get_node_by_key(hash_t *hash, void *key, unsigned int key_size);

hash_t* hash_alloc(unsigned int buckets, hashfunc_t hash_func)  //·ÖÅä¿Õ¼ä
{
	hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
	//assert(hash != NULL)
	hash->buckets = buckets;
	hash->hash_func = hash_func;
	int size = buckets * sizeof(hash_node_t *);
	hash->nodes = (hash_node_t **)malloc(size);
	memset(hash->nodes, 0, size);
	return hash;
}

void* hash_add_entry(hash_t *hash, void *key, unsigned int key_size, void* value, unsigned int value_size)
{

}

void hash_lookup_entry(hash_t *hash, void *key, unsigned int key_size)
{

}

void hash_free_entry(hash_t *hash, void *key, unsigned int key_size)
{

}

hash_node_t** hash_get_bucket(hash_t *hash, void *key)
{

}
hash_node_t* hash_get_node_by_key(hash_t *hash, void *key, unsigned int key_size)
{

}