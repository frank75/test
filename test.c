#include <stdio.h>
#include "test.h"

void print_bits(unsigned char x)
{
	int i;

	printf("0b");

	for (i = 8 * sizeof(x) - 1; i >= 0; i--) {
		(x & (1 << i)) ? putchar('1') : putchar('0');
	}

	printf("\n");
}

