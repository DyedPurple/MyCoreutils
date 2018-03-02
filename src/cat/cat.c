#include <stdio.h>
#include <stdlib.h>

#include "cat.h"

void print_usage(char *prog_location) {
	fprintf(stderr, "usage: %s file [file, ...]\n", prog_location);
	exit(EXIT_FAILURE);
}

int cat_from_stdin() {

	char c;			/* Char being read from file */

	while ((c = getchar()) != EOF) {
		putchar(c);
	}

	return 0;
}

int cat_file(FILE *fp) {

	char c;			/* Char being read from file */
	char prev_c;	/* Previous char read from file */

	c = getc(fp);

	if (c == EOF) {
		return 0;
	}

	while (c != EOF) {
		putchar(c);
		prev_c = c;
		c = getc(fp);
	}

	if (prev_c != '\n') {
		putchar('\n');
	}

	return 0;
}

int main(int argc, char **argv) {

	FILE *fp;
	int arg_i;		/* Argument parser pointer */
	int return_code = 0; /* Default to returning success */

	/* Read input from stdin */
	if (argc == 1) {
		return_code = cat_from_stdin();
	}

	/* Read input from files */
	else {
		for (arg_i = 1; arg_i < argc; arg_i++) {

			fp = fopen(argv[arg_i], "r");
			if (fp == NULL)	{
				fprintf(stderr, "WARNING: Failed to open input file %s\n. Continuing...", argv[arg_i]);
				continue;
			}

			return_code = cat_file(fp);

			if (fclose(fp) == EOF) {
				fprintf(stderr, "WARNING: Failed to close %s. Continuing...\n", argv[arg_i]); 
			}
		}
	}
	
	return return_code;
}
