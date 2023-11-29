#include <stdio.h>

#include "memory.h"

int main(void)
{
	int *buffer = psmalloc(3 * sizeof(int));
	buffer[0] = 3;
	buffer[1] = 2;
	buffer[2] = 1;
	for (int i = 0; i < 3; i++) {
		printf("%d\n", buffer[i]);
	}
	// psfree(buffer);
	return 0;
}
