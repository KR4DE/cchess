#include "test.h"
#include "board.h"

int main(void)
{
	board_init();

	expect(board_at('a', '1') == 'R');
	expect(board_at('b', '1') == 'N');
	expect(board_at('c', '1') == 'B');
	expect(board_at('d', '1') == 'Q');
	expect(board_at('e', '1') == 'K');
	expect(board_at('f', '1') == 'B');
	expect(board_at('g', '1') == 'N');
	expect(board_at('h', '1') == 'R');

	expect(board_at('a', '8') == 'r');
	expect(board_at('b', '8') == 'n');
	expect(board_at('c', '8') == 'b');
	expect(board_at('d', '8') == 'q');
	expect(board_at('e', '8') == 'k');
	expect(board_at('f', '8') == 'b');
	expect(board_at('g', '8') == 'n');
	expect(board_at('h', '8') == 'r');

	for (char file = 'a'; file <= 'h'; file++) {
		expect(board_at(file, '2') == 'P');
		expect(board_at(file, '7') == 'p');
	}

	for (char rank = '3'; rank <= '6'; rank++)
		for (char file = 'a'; file <= 'h'; file++)
			expect(board_at(file, rank) == '.');

	struct square src = {'e', '2'};
	struct square dst = {'e', '4'};

	board_set(src, '.');
	board_set(dst, 'P');

	expect(board_is_empty(src));
	expect(board_get(dst) == 'P');

	exit_test();
}
