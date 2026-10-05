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

	board_init();

	while (1) {
		display_clear();
		display_board();
		display_prompt();

		if (input_read(input, sizeof(input)) == INPUT_TOO_LONG)
			continue;

		if (strcmp(input, "quit") == 0)
			return;

		if (move_parse_lan(input, &move) == MOVE_INVALID)
			continue;

		move_apply(move);
	}
}
