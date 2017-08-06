CC=gcc
FLAGS=-c -g -Wall -DDEBUG

all: tree_sort

tree_sort: bst.o tree_sort.o
	$(CC) bst.o tree_sort.o -o tree_sort
	
bst.o: bst.c bst.h
	$(CC) $(FLAGS) bst.c
	
tree_sort.o: tree_sort.c bst.h
	$(CC) $(FLAGS) tree_sort.c
	

