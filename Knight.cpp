#include "Knight.h"


bool Knight::isMoveValid(const Position position, const Board* board) const
{
	// Get the blocks different (unsinged)
	int dy = std::abs(int(position.getY() - '0') - int(_position.getY() - '0'));
	int dx = std::abs((position.getX() - 'a' + 1) - (this->_position.getX() - 'a' + 1));

	// Knight can go above players and can move 2 for x ot y and 1 for the other
	if ((dx == 2 && dy == 1) || (dy == 2 && dx == 1))
	{
		return true;
	}

	return false;
}
