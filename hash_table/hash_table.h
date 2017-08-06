#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

typedef struct node Node;
struct node {
	int data;
	Node *next;
	
};

typedef struct hash_scheme Scheme;
struct hash_scheme {
	unsigned int a;
	unsigned int b;
	int size;
	
};

void *emalloc(size_t request);
Node *new_node(int num);
void free_mem(void *p);
Scheme *new_hash_scheme(unsigned int a_new, unsigned int b_new, int size_new);
int hash_function(Scheme *hash, int ins);
Node *find_node(Scheme *hash, Node *table[], int key);
void hash_number(Scheme *hash, Node *table[], int ins);
int look_up(Scheme *hash, Node *table[], int key);
void free_table(Scheme *hash, Node *table[]);

#endif