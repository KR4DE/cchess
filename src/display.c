#include "display.h"
#include "board.h"
#include <stdio.h>

#define SPACES 4

void display_clear(void)
{
	puts("\033[2J\033[H");
}

void display_board(void)
{
	printf("%*s  +------------------------+\n", SPACES, "");
	for (int row = 7; row >= 0; row--) {
		printf("%*s%d |", SPACES, "", row + 1);
		for (int col = 0; col < 8; col++)
			printf(" %c ", board_get(row << 3 | col));
		puts("|");
	}
	printf("%*s  +------------------------+\n", SPACES, "");
	printf("%*s    a  b  c  d  e  f  g  h\n\n", SPACES, "");
}

void display_message(const char *msg)
{
	printf("%*s%s", SPACES, "", msg);
	fflush(stdout);
}
