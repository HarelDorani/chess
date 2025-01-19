#include "Game.h"
#include "Console.h"


int main(void) 
{
	std::string move = "", currSrc = "", currDst = "";
	std::string moveFeedback[9] = {"Moved.", "Moved - chess on the enemy!", "Invalid Move, the source slot does not contain a piece of the current player.", "Invalid move, there is a piece of the current player on the target place.", "Invalid move, move will result in check on the current player.", "Invalid move, invalid square indexes", "Invalid Move, illegal movement of a piece type.", "Invalid move, source and destination squares are the same.", "Moved, chess has been played!"};
	int isValid = 0;

	Game game;
	game.startGame();
	//run the game
	while (true)
	{
		std::cout << "curr board: " << game.getBoard().getBordStr() << std::endl;
		game.getBoard().displayBoard();
		std::cout << "Current turn:" << game.getCurrentPlayer().getColor() << std::endl;

		do {
			//get the move
			std::cout << "please enter a move(a1c5)" << std::endl;
			std::cin >> move;

			//convent the str to a position
			currSrc = move.substr(0, 2);
			currDst = move.substr(2, 2);

			isValid = game.getBoard().isMoveValid(strToPosition(currSrc), strToPosition(currDst), game.getCurrentPlayer());
				//print the option
			std::cout << isValid << ": " << moveFeedback[isValid] << std::endl;

		} while(isValid != 1 && isValid != 0 && isValid != 8);

		game.getBoard().movePiece(strToPosition(currSrc), strToPosition(currDst));
		//check if check
		if (game.isCheck()) 
		{
				isValid = 1;
		}
		if (game.onSelfCheck())
		{
			isValid = 4;
			game.getBoard().movePiece(strToPosition(currDst), strToPosition(currSrc));
		}
		
		//move to the next turn
		game.switchTurn();
		//game.getBord().displayBoard();
	}
	return 0;
}