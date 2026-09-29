#include "game.h"
#include "move.h"
#include "board.h"
#include "display.h"
#include "input.h"
#include <string.h>

#define BUFFER_SIZE 8

void game_start(void)
{
	char input[BUFFER_SIZE];
	struct move move;

	board_reset();

	while (1) {
		display_clear();
		display_message("CChess\n\n");
		display_board();
		display_message("> ");

		if (input_read(input, sizeof(input)) == INPUT_INVALID)
			continue;

		if (strcmp(input, "quit") == 0)
			return;

		if (move_parse(input, &move) == MOVE_INVALID)
			continue;

		move_apply(move);
	}
}
