#include "Bishop.h"
#include <cmath>
#include "Board.h"

Bishop::Bishop(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_BISHOP : BLACK_BISHOP) {
}

const char* Bishop::getName() {
	return "BISHOP";
}

bool Bishop::canMove(BoardPiece* bp, Entity* brd) {
	Board *board = dynamic_cast<Board*>(brd);
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	int x = abs(destination.x - current.x);
	int y = abs(destination.y - current.y);
	if (x == y)
	{
		//move is legal, now make sure no obstacles on the way
		int dirX = (destination.x - current.x) / x;
		int dirY = (destination.y - current.y) / x;
		int i = current.x + dirX, j = current.y + dirY;
		for (; i!= destination.x; i+=dirX, j+=dirY) {
			if (!board->getBoardPiece(i,j)->isEmpty()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Bishop::canBeat(Figure* fig, Entity* brd) {
	if (this->getColor() == fig->getColor()) return false;
	return canMove(fig->getPiece(), brd);	
}