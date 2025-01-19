#pragma once

#include "Board.h"
#include <cctype> 

class Player {
protected:
	std::string _color; // Color of player
	
	//King* _king;

public:
	Player();
	Player(const std::string color);
	virtual ~Player();

	bool isCheck(Board board, const Position srcPosition, const Position dstPosition, Player oponent); // Checking if player is on check

	void setColor(std::string color);

	// Getters
	std::string getColor() const; 
};
