#include "King.h"

bool King::isMoveValid(const Position position, const Board* board) const
{
	//get the blocks different
	int dy = int(position.getY() - '0') - int(_position.getY() - '0');
	int dx = (position.getX() - 'a' + 1) - (this->_position.getX() - 'a' + 1);
	dy = std::abs(dy);
	dx = std::abs(dx);
	// King can only move in his 1 block radius
	if ((dx <= 1) && (dy <= 1) && !(dx == 0 && dy == 0))
	{
		return true;
	}

	return false;
}
