#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum input_status input_read(char *buffer, size_t size)
{
	char *newline;
	int c;

	if (fgets(buffer, size, stdin) == NULL)
		exit(0);

	if ((newline = strchr(buffer, '\n')) != NULL) {
		*newline = '\0';
		return INPUT_OK;
	}

	if ((c = getchar()) == '\n')
		return INPUT_OK;

	while ((c = getchar()) != '\n' && c != EOF);

	if (c == '\n')
		return INPUT_INVALID;
	else
		exit(0);
}
