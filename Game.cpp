#include "Game.h"

Game::Game() {
	_black.setColor("black");
	_white.setColor("white");
}

Game::~Game() {
}

void Game::startGame() {	
								//RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1
	std::string startingPieces = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1";
	if (startingPieces[65] == '1') {
		this->_currentTurn.setColor("black");
	}
	else {
		this->_currentTurn.setColor("white");
	}
	startingPieces.pop_back();
	// Inalize the board with pieces according to string
	this->_board = Board(startingPieces);


	
}

void Game::switchTurn() {
	if (this->_currentTurn.getColor() == "white") {
		this->_currentTurn.setColor("black");
	}
	else {
		this->_currentTurn.setColor("white");
	}
}

Player Game::getCurrentPlayer() const
{
	return this->_currentTurn;
}

Board& Game::getBoard()
{
	return this->_board;
}

bool Game::isCheck(const Position srcPosition, const Position dstPosition) {
	// Check if the current player's king is in check
	if (_currentTurn.getColor() == "black") {
		return _white.isCheck(this->_board, srcPosition, dstPosition, _white); // White attacks Black's king
	}
	else {
		return _black.isCheck(this->_board, srcPosition, dstPosition, _black); // Black attacks White's king
	}
	return false;
}

bool Game::onSelfCheck(const Position srcPosition, const Position dstPosition) {


	// Check if the current player's king is in check after the move
	if (_currentTurn.getColor() == "white") {
		return _black.isCheck(this->_board, srcPosition, dstPosition, _white); // Black threatens White's king
	}
	else {
		return _white.isCheck(this->_board, srcPosition, dstPosition, _black); // White threatens Black's king
	}
}
