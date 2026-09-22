#ifndef CCHESS_BOARD_H
#define CCHESS_BOARD_H

void board_reset(void);
char board_get(int square);
void board_set(int square, char piece);

#endif /* CCHESS_BOARD_H */
