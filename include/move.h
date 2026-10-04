#ifndef CCHESS_MOVE_H
#define CCHESS_MOVE_H

#include "board.h"

enum move_status {
	MOVE_OK,
	MOVE_INVALID
};

struct move {
	struct square from;
	struct square to;
	char promotion;
};

enum move_status move_parse(const char *input, struct move *move);
void move_apply(struct move move);

#endif /* CCHESS_MOVE_H */
