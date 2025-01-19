#pragma once
#include "Player.h"

#include <string>
#include <iostream>

#define SIZE 8

class Game {
protected:
	Player _currentTurn;
	Board _board;
	Player _black;
	Player _white;

public:
	Game();
	virtual ~Game();

	/*
	*  Founction is inalizing the game board and setting the starting player to black
	*  Input - none.
	*  Output - none.
	*/
	void startGame();

	/*
	*  Founction is switching turn to other player
	*  Input - none.
	*  Output - none.
	*/
	void switchTurn();

	/*
	*  Founction is switching turn to other player
	*  Input - none.
	*  Output - none.
	*/

	// Getters
	Player getCurrentPlayer() const;
	Board& getBoard();

	/*
	*  Founction is checking if the other player is on check
	*  Input - srcPosition and dstPosition of move .
	*  Output - none.
	*/
	bool isCheck(const Position srcPosition, const Position dstPosition);

	/*
	*  Founction is checking if the curr player is on check
	*  Input - srcPosition and dstPosition of move .
	*  Output - none.
	*/
	bool onSelfCheck(const Position srcPosition, const Position dstPosition);

};
