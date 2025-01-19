#pragma once
#include "Piece.h"

class Rook : virtual public Piece {
public:
	Rook(const std::string& name, const std::string& color, const Position& position)
		: Piece(name, color, position) {}
	virtual ~Rook(){}

	/*
	*  Founction is checking if piece movement is valid acording to game rules, for rook: can move onlt in one line, or y only or x only
	*  Input - destenation position of movement, pointer to game board
	*  Output - true if movement is valid, false if not
	*/
	bool isMoveValid(const Position position, const Board* board)const override;
};