#pragma once
#include <iostream>
#include <string>

class Position {
protected:
	char _x;
	char _y;

public:
	Position();
	Position(const char x, const char y);
	virtual ~Position();

	bool operator==(const Position other) const;
	bool operator!=(const Position other) const;
	Position& operator=(const Position& other);
	bool inBoard() const;

	// Getters
	char getX() const;
	char getY() const;
};
