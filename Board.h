#pragma once

#define SIZE 8

#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Empty.h"
#include "Player.h"

class Player;
class Board {
protected:
	Piece* _board[SIZE][SIZE];
	std::string _bordStr;

public:
	Board();
	Board(const std::string boardPieces); // Creating board and initialazing
	virtual ~Board();

	/*
	*  Founction is moving source piece to the deraction place
	*  Input - source position and destenation position of movement
	*  Output - none.
	*/
	void movePiece(Position srcPosition, Position dstPosition);

	/*
	*  Founction is checking if movement is valid
	*  Input - source position and destenation position of movement, current turn player
	*  Output - none.
	*/
	char* isMoveValid(const Position srcPosition, const Position dstPosition, const Player currPlayerTurn) const; // Checking if move valid (basic first checks)
	
	/*
	*  Founction is printing board
	*  Input - none.
	*  Output - none.
	*/
	void displayBoard(); // Displays board to screen 
	
	/*
	*  Founction is getting position and returning the piece in this position in the board
	*  Input - position to find
	*  Output - the piece in the position
	*/
	Piece* getPieceAt(Position position) const;

	// Getters
	Piece* (&getBoard())[SIZE][SIZE];
	std::string getBordStr();

};
