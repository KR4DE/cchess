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
	for (char rank = '8'; rank >= '1'; rank--) {
		printf("%*s%c |", SPACES, "", rank);
		for (char file = 'a'; file <= 'h'; file++)
			printf(" %c ", board_at(file, rank));
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
