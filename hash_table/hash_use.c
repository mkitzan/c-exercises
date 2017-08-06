#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

int main(int argc, char *argv[]) {
	int a, b, size, i;
	int args[argc-4];
	Scheme *hash;
	
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	size = atoi(argv[3]);
	
	for(i = 0; i < argc-4; i++) {
		args[i] = atoi(argv[i+4]);
	}
	
	Node *table[size];
	for(i = 0; i < size; i++) 
		table[i] = new_node(-1);
	
	hash = new_hash_scheme(a, b, size);
	for(i = 0; i < argc-4; i++)
		hash_number(hash, table, args[i]);
	
	for(i = 0; i < argc-4; i++) {
		printf("Look-up: %d, %s\n", args[i], (look_up(hash, table, args[i]) == 1) ? "succeeded":"failed");
	}
	
	free_table(hash, table);
}