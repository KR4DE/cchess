#ifndef CCHESS_BOARD_H
#define CCHESS_BOARD_H

#include <stdbool.h>

struct square {
	char file;
	char rank;
};

void board_init(void);
char board_get(struct square square);
char board_at(char file, char rank);
void board_set(struct square square, char piece);
bool board_is_empty(struct square square);

#endif /* CCHESS_BOARD_H */
