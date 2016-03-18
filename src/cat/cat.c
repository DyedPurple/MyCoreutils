#include <stdio.h>
#include <stdlib.h>

#ifndef GH_CAT_H
#include "cat.h"
#endif /* GH_CAT_H */

void print_usage(char *prog_location) {
	fprintf(stderr, "usage: %s file [file, ...]\n", prog_location);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {

	FILE *fp;
	int arg_i;		/* Argument parser pointer */
	char c;			/* Char being read from file */
	char prev_c;	/* Previous char read from file */

	/* Read input from stdin */
	if (argc == 1) {
		while ((c = getchar()) != EOF) {
			putchar(c);
		}
	}

	/* Read input from files */
	else {
		for (arg_i = 1; arg_i < argc; arg_i++) {

			fp = fopen(argv[arg_i], "r");
			if (fp == NULL)	{
				fprintf(stderr, "WARNING: Failed to open input file %s\n. Continuing...", argv[arg_i]);
				continue;
			}

			c = getc(fp);

			if (c == EOF) {
				continue;
			}

			while (c != EOF) {
				putchar(c);
				prev_c = c;
				c = getc(fp);
			}

			if (prev_c != '\n') {
				putchar('\n');
			}

			if (fclose(fp) == EOF) {
				fprintf(stderr, "WARNING: Failed to close %s. Continuing...\n", argv[arg_i]); 
			}
		}
	}
	
	return 0;
}
