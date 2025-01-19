/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "Game.h"
#include "Console.h"
#include <iostream>
#include <thread>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));
	string move, currSrc, currDst;
	char isValid[2];

	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}

	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1"); // just example...

	// Send the board string
	p.sendMessageToGraphics(msgToGraphics);

	// Get player move from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	Game game;
	game.startGame();

	while (msgFromGraphics != "quit")
	{
		// Handle move 

		// Convent the str to a position
		move = msgFromGraphics;
		cout << msgFromGraphics << endl;
		currSrc = move.substr(0, 2);
		currDst = move.substr(2, 2);

		// Checking move validation
		strcpy_s(isValid, game.getBoard().isMoveValid(strToPosition(currSrc), strToPosition(currDst), game.getCurrentPlayer()));
		
		if (strcmp(isValid, "0") == 0)
		{
			if (game.onSelfCheck(strToPosition(currSrc), strToPosition(currDst)))
			{
				printf("on check");
				strcpy_s(isValid, "4");
			}
		}


		// Sending the result of the operation to graphics
		strcpy_s(msgToGraphics, isValid);

		// If move is valid mov the piece in backend and switch the turn
		if (strcmp(isValid, "1") == 0 || strcmp(isValid, "0") == 0 || strcmp(isValid, "8") == 0) {
			game.getBoard().movePiece(strToPosition(currSrc), strToPosition(currDst));
			game.getBoard().displayBoard();
			game.switchTurn();
		}

		// Return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// Get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
		cout << msgFromGraphics;
	}

	p.close();
}