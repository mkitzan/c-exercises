#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node *build_tree(int argc, char *argv[]) {
	Node *root;
	Node *temp;
	int i;
	root = new_node(atoi(argv[1]));
	
	for(i = 2; i < argc; i++) {
		temp = new_node(atoi(argv[i]));
		insert_node(root, temp);
	}
	
	return root;
}

int main(int argc, char *argv[]) {
	Node *root;
	root = build_tree(argc, argv);
	print_tree(root);
	free_tree(root);
}