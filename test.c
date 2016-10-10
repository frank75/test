#include <stdio.h>
#include <libgen.h>
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

void uses(char *progname)
{
		printf("Składnia: %s [OPCJA]...\n",progname);
		printf("Wypisanie liczby dziesiętnej w postaci binarnej\n\n");
		printf("  -d N\t\t\tN - liczba z przedziału 0..255\n");
		printf("  -h\t\t\twyświetlenie tego opisu i zakończenie\n");
}

