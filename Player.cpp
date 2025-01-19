#include "Player.h"

Player::Player() {

}

Player::Player(const std::string color) {
	this->_color = color;
}

Player::~Player() {
	this->_color.clear();
}

bool Player::isCheck(Board board, const Position srcPosition, const Position dstPosition, Player opponent) {
    // Simulate the move
    Board simulatedBoard = board; // Ensure Board has a proper deep copy implementation
    simulatedBoard.movePiece(srcPosition, dstPosition);

    // Find the king's position
    Position kingPosition;
    bool kingFound = false;

    for (int i = 0; i < SIZE && !kingFound; i++) {
        for (int j = 0; j < SIZE && !kingFound; j++) {
            Position pos('a' + j, '1' + (SIZE - 1 - i));
            Piece* piece = simulatedBoard.getPieceAt(pos);

            //check for the king based on the player's color
            if ((this->_color == "white" && piece->getName() == "K") ||
                (this->_color == "black" && piece->getName() == "k")) {
                kingPosition = pos;
                kingFound = true;
            }
        }
    }


    std::cout << "\nKing position: X=" << kingPosition.getX() << ", Y=" << kingPosition.getY() << "\n";

    //check for opponent threats to the king
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            Position pos('a' + j, '1' + (SIZE - 1 - i));
            Piece* piece = simulatedBoard.getPieceAt(pos);
            char moveValidity[1024];
            //check if the opponent's piece can move to the king's position
            strcpy_s(moveValidity, simulatedBoard.isMoveValid(piece->getPosition(), kingPosition, *this));
            std::cout << std::endl << moveValidity << std::endl;
            if (strcmp(moveValidity, "1") == 0 || strcmp(moveValidity, "0") == 0) {
                std::cout << "Threat from piece " << piece->getName()
                    << " at position X=" << piece->getPosition().getX()
                    << ", Y=" << piece->getPosition().getY() << "\n";
                return true;
            }
        }
    }

    return false;
}



void Player::setColor(std::string color)
{
	this->_color = color;
}

// Getters
std::string Player::getColor() const {
	return this->_color;
}

