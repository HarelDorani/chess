#include "Rook.h"
#include "Board.h"

bool Rook::isMoveValid(const Position position, const Board* board)const
{
	// Get the blocks different
    int dy = int(position.getY() - '0') - int(_position.getY() - '0');
    int dx = (position.getX() - 'a' + 1) - (this->_position.getX() - 'a' + 1);

	// Rook can only move only x or only y
	if ((dy != 0 && dx == 0) || (dx != 0 && dy == 0))
	{
        int i = 0;
        // Going trught all the pieces between (y)
        for (i = 0; i < std::abs(dy); i++) {
            // Going downword y 
            if (dy < 0 && board->getPieceAt(Position(position.getX(), position.getY() + i))->getName()[0] != '#') {
                return false;
            }
            // Going uppword y
            else if (dy > 0 && board->getPieceAt(Position(position.getX(), position.getY() - i))->getName()[0] != '#') {
                return false;
            }
        }

        // Going trught all the pieces between (x)
        for (i = 0; i < std::abs(dx); i++) {
            if (dx > 0 && board->getPieceAt(Position(position.getX() - i, position.getY()))->getName()[0] != '#') {
                return false;
            }
            else if (dx < 0 && board->getPieceAt(Position(position.getX() + i, position.getY()))->getName()[0] != '#') {
                return false;
            }
        }
        return true;
    }

	// If the move are acording to law and there are no pieces between src and dest then move is valid
    return false;
}
