#include "display.h"
#include "board.h"
#include <stdio.h>

#define SPACES "    " /* 4 */

void display_clear(void)
{
	puts("\033[2J\033[H");
}

void display_board(void)
{
	puts(SPACES "  CChess 0.1.0");
	puts(SPACES "  +------------------------+");
	for (char rank = '8'; rank >= '1'; rank--) {
		printf(SPACES "%c |", rank);
		for (char file = 'a'; file <= 'h'; file++)
			printf(" %c ", board_at(file, rank));
		puts("|");
	}
	puts(SPACES "  +------------------------+");
	puts(SPACES "    a  b  c  d  e  f  g  h\n");
}

void display_prompt(void)
{
	fputs(SPACES "> ", stdout);
	fflush(stdout);
}
