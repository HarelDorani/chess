#pragma once
#include "Position.h"

class Board;

class Piece {
protected:
    std::string _name;
    std::string _color;
    Position _position;

public:
    Piece();
    // Constractour
    Piece(const std::string name, const std::string color, const Position position);
    virtual ~Piece();
    
    /*
    *  Founction is checking if piece movement is valid acording to game rules (the func is pure virtual becuase every piece have diffrent movement rules)
    *  Input - destenation position of movement, pointer to game board
    *  Output - true if movement is valid, false if not
    */
    virtual bool isMoveValid(const Position dstPosition, const Board* board) const = 0;

    /*
    *  Founction is changing position to the deraction position
    *  Input - destenation position of movement
    *  Output - none.
    */
    void move(const Position newPosition);

    // Getters
    Position getPosition() const;
    std::string getName() const;
    std::string getColor() const;

    //setters
    void setName(std::string name);
    void setColor(std::string color);
    void setPosition(Position position);
}; 