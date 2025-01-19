#pragma once
#include "Piece.h"

class Bishop : virtual public Piece {
public:
    Bishop(const std::string& name, const std::string& color, const Position& position)
        : Piece(name, color, position) {}
    virtual ~Bishop() {}

    /*
    *  Founction is checking if piece movement is valid acording to game rules, for bishop: can go diagnoze to all spaces
    *  Output - true if movement is valid, false if not
    */
    bool isMoveValid(const Position position, const Board* board) const override;
};