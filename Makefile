CC = gcc
CCFLAGS = -Wall -Werror -g3

all: hash_table_test

hash_table.o: hash_table.c
	$(CC) $(CCFLAGS) hash_table.c -c -o hash_table.o

hash_table_test: hash_table_test.c hash_table.o
	$(CC) $(CCFLAGS) hash_table_test.c hash_table.o -o hash_table_test
	
clean:
	rm *.o *_test
