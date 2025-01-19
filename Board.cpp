#include "Board.h"

Board::Board() {

}

Board::Board(const std::string boardPieces) {
    int i = 0, j = 0;
    char piece;
    this->_bordStr = boardPieces;
    // Init every index acording to the string
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            piece = boardPieces[i * SIZE + j];

            Position currPosition('a' + j, '1' + (SIZE - 1 - i));
            Piece* currPiece = NULL;

            switch (piece)
            {
            case 'K': // King (Black)
                currPiece = new King("K", "black", currPosition);
                break;
            case 'k': // King (White)
                currPiece = new King("k", "white", currPosition);
                break;
            case 'Q': // Queen (Black)
                currPiece = new Queen("Q", "black", currPosition);
                break;
            case 'q': // Queen (White)
                currPiece = new Queen("q", "white", currPosition);
                break;

                
            case 'R': // Rook (Black)
                currPiece = new Rook("R", "black", currPosition);
                break;
            case 'r': // Rook (White)
                currPiece = new Rook("r", "white", currPosition);
                break;


            case 'N': // Knight (Black)
                currPiece = new Knight("N", "black", currPosition);
                break;
            case 'n': // Knight (White)
                currPiece = new Knight("n", "white", currPosition);
                break;


            case 'B': // Bishop (Black)
                currPiece = new Bishop("B", "black", currPosition);
                break;
            case 'b': // Bishop (White)
                currPiece = new Bishop("b", "white", currPosition);
                break;


            case 'P': // Pawn (Black)
                currPiece = new Pawn("P", "black", currPosition);
                break;
            case 'p': // Pawn (White)
                currPiece = new Pawn("p", "white", currPosition);
                break;


            case '#': // Empty square
                currPiece = new Empty("#", "-", currPosition);
                break;
            }
            //put the piece to the array
            this->_board[SIZE - 1 - i][j] = currPiece;
        }
    }
}

Board::~Board() {

}

void Board::movePiece(Position srcPosition, Position dstPosition)
{
    int srcIndex = 0;
    int dstIndex = 0;

    // Get the indexs
    int srcX = int(srcPosition.getX() - 'a');
    int srcY = int(srcPosition.getY() - '0') - 1;
    int dstX = int(dstPosition.getX() - 'a');
    int dstY = int(dstPosition.getY() - '0') - 1;

    // switching pieces positions
    this->_board[srcY][srcX]->move(this->_board[dstY][dstX]->getPosition());
    this->_board[dstY][dstX]->move(this->_board[srcY][srcX]->getPosition());

    // Moving src piece to dst position
    this->_board[dstY][dstX] = this->_board[srcY][srcX];

    // Changing src piece to emphty pieace
    this->_board[srcY][srcX] = new Empty("#", "-", this->_board[dstY][dstX]->getPosition());

    // Changing the string
    srcIndex = (SIZE - 1 - srcY) * SIZE + srcX; 
    dstIndex = (SIZE - 1 - dstY) * SIZE + dstX;

    this->_bordStr[dstIndex] = this->_bordStr[srcIndex];
    this->_bordStr[srcIndex] = '#';
}

char* Board::isMoveValid(const Position srcPosition, const Position dstPosition, const Player currPlayerTurn) const {
    // Get the indexs
    int srcX = (srcPosition.getX() - 'a');
    int srcY = (srcPosition.getY() - '0') - 1;
    int dstX = int(dstPosition.getX() - 'a');
    int dstY = int(dstPosition.getY() - '0') - 1;

    char value[2];
    // chess on the opp (VALID 1)

    // Check if the src piece is current player piece (error 2)
    if (this->_board[srcY][srcX]->getColor() != currPlayerTurn.getColor()) {
        strcpy_s(value, "2");
        return value;
    }

    // Check that the dest piece wont be with the current players (error 3)
    if (this->_board[dstY][dstX]->getColor() == currPlayerTurn.getColor()) {
        strcpy_s(value, "3");
        return value;
    }

    // chess on the curr player (error 4)

    // Check that both positions are in the board (error 5)
    if (!(srcPosition.inBoard() && dstPosition.inBoard())) {
        strcpy_s(value, "5");
        return value;
    }

    // Checking if piece move is valid
    if (!this->_board[srcY][srcX]->isMoveValid(dstPosition, this)) {
        strcpy_s(value, "6");
        return value;
    }

    // Check if both positions are the same (error 7)
    if (srcPosition == dstPosition) {
        strcpy_s(value, "7");
        return value;
    }

    // If everything is alr then return 0!
    strcpy_s(value, "0");
    return value;
}

void Board::displayBoard() 
{
    unsigned int i = 0; 
    unsigned int  j = 0;

    // Run through the array (upside down so the player will see it right)
    for (i = SIZE; i > 0; i--)
    {
        for (j = 0; j < SIZE; j++)
        {
            std::cout << this->_board[i - 1][j]->getName() << " ";
        }
        std::cout << std::endl;
    }
}

Piece* Board::getPieceAt(Position position)const
{
    // Get the indexs
    int dstX = int(position.getX() - 'a');
    int dstY = int(position.getY() - '0') - 1;

    // Return piece at the spetific index
    return this->_board[dstY][dstX];
}

Piece* (&Board::getBoard())[SIZE][SIZE]{
    // Retrun the board
    return this->_board;
}

std::string Board::getBordStr(){
    return this->_bordStr;
}
