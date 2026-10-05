#ifndef CCHESS_MOVE_H
#define CCHESS_MOVE_H

#include "board.h"

struct move {
	struct square from;
	struct square to;
	char promotion;
};

enum move_status {
	MOVE_OK,
	MOVE_INVALID
};

enum move_status move_parse_lan(const char *str, struct move *move);
void move_apply(struct move move);

#endif /* CCHESS_MOVE_H */
