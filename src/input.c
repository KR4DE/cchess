#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum input_status input_read(char *buffer, size_t size)
{
	char *newline;
	int c;

	if (fgets(buffer, size, stdin) == NULL) {
		putchar('\n');
		exit(0);
	}

	if ((newline = strchr(buffer, '\n')) != NULL) {
		*newline = '\0';
		return INPUT_READ_OK;
	}

	if ((c = getchar()) == '\n')
		return INPUT_READ_OK;

	while ((c = getchar()) != '\n' && c != EOF);

	if (c == '\n')
		return INPUT_TOO_LONG;

	putchar('\n');
	exit(0);
}
