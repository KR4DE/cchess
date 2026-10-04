#include "move.h"
#include "board.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static bool is_valid(const char *input)
{
	size_t len = strlen(input);

	if (len != 4 && len != 5)
		return false;

	if (input[0] < 'a' || input[0] > 'h' ||
	    input[1] < '1' || input[1] > '8' ||
	    input[2] < 'a' || input[2] > 'h' ||
	    input[3] < '1' || input[3] > '8')
		return false;

	if (len == 5 && strchr("qrbn", input[4]) == NULL)
		return false;

	return true;
}

enum move_status move_parse(const char *input, struct move *move)
{
	if (!is_valid(input))
		return MOVE_INVALID;

	move->from.file = input[0];
	move->from.rank = input[1];
	move->to.file   = input[2];
	move->to.rank   = input[3];
	move->promotion = input[4];

	if (board_is_empty(move->from))
		return MOVE_INVALID;

	return MOVE_OK;
}

void move_apply(struct move move)
{
	char piece = board_get(move.from);

	if (move.promotion) {
		if (isupper(piece))
			piece = toupper(move.promotion);
		else
			piece = move.promotion;
	}

	board_set(move.from, '.');
	board_set(move.to, piece);
}
