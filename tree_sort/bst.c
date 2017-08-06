#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"


void *emalloc(size_t new) {
	void *p;
	
	p = malloc(new);
	if(p == NULL) {
		printf("malloc returned NULL, exiting program\n");
		exit(1);
	}
	
	return p;
}

Node *new_node(int num) {
	Node *new;
	new = (Node *) emalloc(sizeof(Node));
	
	new->data = num;
	new->left = NULL;
	new->right = NULL;
	
	return new;
}

void free_node(Node *rem) {
	assert(rem != NULL);
	free(rem);
}

void insert_node(Node *parent, Node *ins) {
	if(ins->data <= parent->data) {
		if(parent->left == NULL)
			parent->left = ins;
		else 
			insert_node(parent->left, ins);
	} else if(ins->data > parent->data) {
		if(parent->right == NULL)
			parent->right = ins;
		else 
			insert_node(parent->right, ins);
	}
}

void print_tree(Node *node) {
	if(node == NULL)
		return;
	
	print_tree(node->left);
	printf("%d ", node->data);
	print_tree(node->right);
}

void free_tree(Node *node) {
	if(node == NULL) 
		return;
	
	free_tree(node->left);
	free_tree(node->right);
	free_node(node);
}

