#include "move.h"
#include "board.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

static bool is_valid_lan(const char *str)
{
	size_t len = strlen(str);

	if (len != 4 && len != 5)
		return false;

	if (str[0] < 'a' || str[0] > 'h' ||
	    str[1] < '1' || str[1] > '8' ||
	    str[2] < 'a' || str[2] > 'h' ||
	    str[3] < '1' || str[3] > '8')
		return false;

	if (len == 5 && strchr("qrbn", str[4]) == NULL)
		return false;

	return true;
}

enum move_status move_parse_lan(const char *str, struct move *move)
{
	if (!is_valid_lan(str))
		return MOVE_INVALID;

	move->from.file = str[0];
	move->from.rank = str[1];
	move->to.file   = str[2];
	move->to.rank   = str[3];
	move->promotion = str[4];

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
