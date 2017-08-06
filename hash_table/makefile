CC=gcc
FLAGS=-c -g -Wall -DDEBUG

all: hash_use

hash_use: hash_use.o hash_table.o
	$(CC) hash_use.o hash_table.o -o hash_use

hash_use.o: hash_use.c hash_table.h
	$(CC) $(FLAGS) hash_use.c
	
hash_table.o: hash_table.c hash_table.h
	$(CC) $(FLAGS) hash_table.c