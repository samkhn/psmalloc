CC = gcc
CCFLAGS = -Wall -Werror -g3

all: hash_table_test psmalloc_test

hash_table.o: hash_table.c
	$(CC) $(CCFLAGS) hash_table.c -c -o hash_table.o

hash_table_test: hash_table_test.c hash_table.o
	$(CC) $(CCFLAGS) hash_table_test.c hash_table.o -o hash_table_test
	
psmalloc_test: psmalloc_test.c hash_table.o
	$(CC) $(CCFLAGS) psmalloc_test.c memory.c hash_table.o -o psmalloc_test

clean:
	rm *.o *_test
