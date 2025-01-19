#pragma once
#include "Piece.h"
#include "Board.h"


class Knight : public Piece {
public:
	Knight(const std::string& name, const std::string& color, const Position& position)
		: Piece(name, color, position) {}
	virtual ~Knight(){}

	/*
	*  Founction is checking if piece movement is valid acording to game rules, for knight: can go 2 for 1 L or R, 2 right or left 1 up or down
	*  Input - destenation position of movement, pointer to game board
	*  Output - true if movement is valid, false if not
	*/
	bool isMoveValid(const Position position, const Board* board) const override;
};