#include "board.h"
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define NUM_SQUARES 64

static char board[NUM_SQUARES];

static inline int index_of(struct square square)
{
	assert(square.file >= 'a' && square.file <= 'h');
	assert(square.rank >= '1' && square.rank <= '8');

	int row = square.rank - '1';
	int col = square.file - 'a';

	return row * 8 + col;
}

void board_init(void)
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

char board_get(struct square square)
{
	return board[index_of(square)];
}

char board_at(char file, char rank)
{
	return board_get((struct square){file, rank});
}

void board_set(struct square square, char piece)
{
	assert(strchr("KQRBNPkqrbnp.", piece) != NULL);

	board[index_of(square)] = piece;
}

bool board_is_empty(struct square square)
{
	return board[index_of(square)] == '.';
}
