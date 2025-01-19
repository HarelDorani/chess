#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece {
protected:
	mutable bool _hasMoved;
public:
	Pawn(const std::string& name, const std::string& color, const Position& position)
		: Piece(name, color, position) {
		_hasMoved = false;
	}
	virtual ~Pawn(){}

	/*
	*  Founction is checking if piece movement is valid acording to game rules, for pawn: if first move - can move 2 or less blocks forword, can eat eside, 1 step forword if no piece there
	*  Input - destenation position of movement, pointer to game board
	*  Output - true if movement is valid, false if not
	*/
	bool isMoveValid(const Position position, const Board* board) const override;
};