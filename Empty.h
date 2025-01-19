#pragma once
#include "Piece.h"
#include "Board.h"

class Empty : public Piece {
public:
	Empty(const std::string& name, const std::string& color, const Position& position)
		: Piece(name, color, position) {}
	virtual ~Empty() {}

	// Empty piece cant move.
	bool isMoveValid(const Position position, const Board* board) const override;
};