#include "board.h"
#include <string.h>

#define NUM_SQUARES 64

static char board[NUM_SQUARES];

void board_reset(void)
{
	/* Little-endian rank-file (LERF) mapping */
	static const char start_state[NUM_SQUARES] = {
		'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
		'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.', '.', '.', '.',
		'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
		'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'
	};

	memcpy(board, start_state, sizeof(board));
}

char board_get(int square)
{
	return board[square];
}

void board_set(int square, char piece)
{
	board[square] = piece;
}
