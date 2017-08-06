#ifndef _BST_H_
#define _BST_H_

typedef struct node Node;
struct node {
	int data;
	Node *left;
	Node *right;
	
};

Node *new_node(int num);
void free_node(Node *rem);
void insert_node(Node *root, Node *ins);
void print_tree(Node *node);
void free_tree(Node *node);

#endif