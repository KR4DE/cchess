#include "test.h"
#include "move.h"
#include "board.h"

int main(void)
{
	board_init();

	struct move move;

	/* Invalid LAN strings */
	expect(move_parse_lan("E2e4", &move) == MOVE_INVALID);
	expect(move_parse_lan("e0e4", &move) == MOVE_INVALID);
	expect(move_parse_lan("e2i4", &move) == MOVE_INVALID);
	expect(move_parse_lan("e2e9", &move) == MOVE_INVALID);
	expect(move_parse_lan("e2e4j", &move) == MOVE_INVALID);
	expect(move_parse_lan("e2e4Q", &move) == MOVE_INVALID);

	/* Empty 'from' square */
	expect(move_parse_lan("e4e5", &move) == MOVE_INVALID);

	/* Valid promotion (chess rules not enforced) */
	expect(move_parse_lan("e2e4q", &move) == MOVE_OK);
	expect(move.from.file == 'e');
	expect(move.from.rank == '2');
	expect(move.to.file == 'e');
	expect(move.to.rank == '4');
	expect(move.promotion == 'q');

	move_apply(move);

	expect(board_is_empty(move.from));
	expect(board_get(move.to) == 'Q');

	/* Valid move */
	expect(move_parse_lan("e7e5", &move) == MOVE_OK);
	expect(!move.promotion);

	move_apply(move);

	expect(board_is_empty(move.from));
	expect(board_get(move.to) == 'p');

	/* Valid capture */
	expect(move_parse_lan("e4e5", &move) == MOVE_OK);

	move_apply(move);

	expect(board_is_empty(move.from));
	expect(board_get(move.to) == 'Q');

	exit_test();
}
