#include "Queen.h"

bool Queen::isMoveValid(const Position position, const Board* board) const {
    // Queen is the connection between bishop and rook
    return Bishop::isMoveValid(position, board) || Rook::isMoveValid(position, board);
}
