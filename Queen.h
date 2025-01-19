#pragma once
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, public Rook {
public:
    Queen(const std::string& name, const std::string& color, const Position& position)
        : Piece(name, color, position), Bishop(name, color, position), Rook(name, color, position) {}

    virtual ~Queen() {}

    /*
    *  Founction is checking if piece movement is valid acording to game rules, for queen: bishop + rook movements 
    *  Input - destenation position of movement, pointer to game board
    *  Output - true if movement is valid, false if not
    */
    bool isMoveValid(const Position position, const Board* board) const override;
};