#ifndef CCHESS_INPUT_H
#define CCHESS_INPUT_H

#include <stddef.h>

enum input_status {
	INPUT_READ_OK,
	INPUT_TOO_LONG
};

enum input_status input_read(char *buffer, size_t size);

#endif /* CCHESS_INPUT_H */
