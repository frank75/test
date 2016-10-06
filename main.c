#include <stdio.h>
#include "test.h"

int main(void)
{
	unsigned char x = 0b00010101;

	printf("%d(dec)=", x);
	print_bits(x);
	return 0;
}

