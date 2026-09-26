#ifndef CCHESS_MOVE_H
#define CCHESS_MOVE_H

enum move_status {
	MOVE_OK,
	MOVE_INVALID
};

struct move {
	int from;
	int to;
	char promotion;
};

enum move_status move_parse(const char *input, struct move *move);
void move_apply(struct move move);

#endif /* CCHESS_MOVE_H */
