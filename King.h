#pragma once
#include "Piece.h"
#include "Board.h"

class King : public Piece {
public:
    King(const std::string& name, const std::string& color, const Position& position)
        : Piece(name, color, position) {}
    virtual ~King() {}

    /*
    *  Founction is checking if piece movement is valid acording to game rules, for king: can move to all squers that 1 block close
    *  Input - destenation position of movement, pointer to game board
    *  Output - true if movement is valid, false if not
    */
    bool isMoveValid(const Position position, const Board* board) const override;
};