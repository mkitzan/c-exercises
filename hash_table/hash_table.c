#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash_table.h"

void *emalloc(size_t request) {
	void *p;
	
	p = malloc(request);
	if(p == NULL) {
		printf("malloc returned NULL, exiting program\n");
	}
	
	return p;
}

Node *new_node(int num) {
	Node *temp;
	temp = (Node *) emalloc(sizeof(Node));
	temp->data = num;
	temp->next = NULL;
	
	return temp;
}

void free_mem(void *p) {
	assert(p != NULL);
	free(p);
}

Scheme *new_hash_scheme(unsigned int a_new, unsigned int b_new, int size_new) {
	Scheme *hash;
	hash = (Scheme *) emalloc(sizeof(Scheme));
	
	hash->a = a_new;
	hash->b = b_new;
	hash->size = size_new;
	
	return hash;
}

int hash_function(Scheme *hash, int ins) {
	return ((hash->a * ins + hash->b) % hash->size);
}

Node *find_node(Scheme *hash, Node *table[], int key) {
	int loc = hash_function(hash, key);
	
	Node *cur = table[loc];
	while(cur->next != NULL)	
		cur = cur->next;
	
	return cur;
}

void hash_number(Scheme *hash, Node *table[], int ins) {
	Node *hash_node;
	Node *ins_point;
	ins_point = find_node(hash, table, ins);
	hash_node = new_node(ins);
	
	ins_point->next = hash_node;
}

int look_up(Scheme *hash, Node *table[], int key) {
	int loc = hash_function(hash, key);
	
	Node *cur = table[loc];
	while(cur->next != NULL) {
		cur = cur->next;
		if(cur->data == key)
			return 1;
	}	
	
	return 0;
}

void free_table(Scheme *hash, Node *table[]) {
	Node *cur;
	Node *pre;
	int i;
	
	for(i = 0; i < hash->size; i++) {
		cur = table[i];
		while(cur != NULL) {
			pre = cur;
			cur = cur->next;
			free_mem(pre);
		}
	}
	
	free_mem(hash);
}



