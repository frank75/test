#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <getopt.h>

#include "test.h"

int main(int argc, char **argv)
{
	//unsigned char x = 0b00010101;
	unsigned char x = 0;

	int aflag = 0;
	char *bvalue = NULL;
	char *dvalue = NULL;
	int index;
	int c;

	opterr = 0;

	while ((c = getopt(argc, argv, "ab:d:")) != -1)
		switch (c) {
		case 'a':
			aflag = 1;
			break;
		case 'b':
			bvalue = optarg;
			break;
		case 'd':
			dvalue = optarg;
			break;
		case '?':
			if (optopt == 'b' || optopt == 'd')
				fprintf(stderr,
					"Option -%c requires an argument.\n",
					optopt);
			else if (isprint(optopt))
				fprintf(stderr,
					"Unknown option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n",
					optopt);
			return 1;
		default:
			abort();
		}

	//printf("aflag = %d, bvalue = %s, dvalue = %s\n", aflag, bvalue, dvalue);

	for (index = optind; index < argc; index++)
		printf("Non-option argument %s\n", argv[index]);

	if (dvalue != NULL)
		x = atoi(dvalue);

	printf("%d(dec)=", x);
	print_bits(x);
	return 0;
}
