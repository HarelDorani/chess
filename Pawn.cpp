#include "Pawn.h"

bool Pawn::isMoveValid(const Position position, const Board* board) const
{
	bool moveSide = false;
	
	int dy = int(position.getY() - '0') - int(_position.getY() - '0');
	int dx = (position.getX() - 'a' + 1) - (this->_position.getX() - 'a' + 1);

	// Pawn can only go forword  if there is no piece hes eating. he can eat only diagnoz
	if ((dy <= 2  || dy <= -2) && dx == 0) {
		if (this->getColor() == "white" && board->getPieceAt(position)->getColor() == "black") {
			return false;
		}
		else if (this->getColor() == "black" && board->getPieceAt(position)->getColor() == "white") {
			return false;
		}
	}

	if (this->getColor() == "white") {
		// Checking if the piece can go aside for eating
		if (std::isupper(board->getPieceAt(position)->getName()[0])) {
			moveSide = true;
		}
		// Checking that piece is not moving backwords
		if (dy < 0) {
			return false;
		}
	}
	else {
		// Checking if the piece can go aside for eating
		if (std::islower(board->getPieceAt(position)->getName()[0])) {
			moveSide = true;
		}
		// Checking that piece is not moving backwords
		if (dy > 0) {
			return false;
		}
	}

	// If first move - can move 2 or less blocks forword, if can eat eside, 1 step forword if no piece there
	if ((!this->_hasMoved && (dy == 2 || dy == -2)&& dx == 0) || (moveSide && (dy == 1 || dy == -1 )&& (dx == 1 || dx == -1)) || (dx == 0 && (dy == 1 || dy == -1) && board->getPieceAt(position)->getName()[0] == '#'))
	{
		this->_hasMoved = true;
		return true;
	}
	return false;
}