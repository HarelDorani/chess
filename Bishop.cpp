#include "Bishop.h"
#include "Board.h"

bool Bishop::isMoveValid(const Position position, const Board* board) const
{
	int i = 0;

	// Get the blocks different
	int dy = int(position.getY() - '0') - int(_position.getY() - '0');
	int dx = (position.getX() - 'a' + 1) - (this->_position.getX() - 'a' + 1);

	// Checking if move is valid
	if (std::abs(dx) == std::abs(dy))
	{
		// Checking if there are pieces in the way 
		for (i = 1; i < std::abs(dy); i++) {
			    // Black piece, moving forword, R                  White piece, moving backwords, R
			if (this->_color == "black" && dy < 0 && dx > 0 || this->_color == "white" && dy < 0 && dx > 0) {
				if (board->getPieceAt(Position(position.getX() - i, position.getY() + i))->getName()[0] != '#') {
					return false;
				}
			}
				     // Black piece, moving forword, L                  White piece, moving backwords, L
			else if (this->_color == "black" && dy < 0 && dx < 0 || this->_color == "white" && dy < 0 && dx < 0) {
				if (board->getPieceAt(Position(position.getX() + i, position.getY() + i))->getName()[0] != '#') {
					return false;
				}
			}
				     // Black piece, moving backwords, R                White piece, moving forword, R
			else if (this->_color == "black" && dy > 0 && dx > 0 || this->_color == "white" && dy > 0 && dx > 0) {
				if (board->getPieceAt(Position(position.getX() - i, position.getY() - i))->getName()[0] != '#') {
					return false;
				}
			}
				     // Black piece, moving backwords, L                 White piece, moving forword, L
			else if (this->_color == "black" && dy > 0 && dx < 0 || this->_color == "white" && dy > 0 && dx < 0 ) {
				if (board->getPieceAt(Position(position.getX() + i, position.getY() - i))->getName()[0] != '#') {
					return false;
				}
			}
		}
		// Checking if the player is going backwords 
		return true;
	}

	return false;
}
