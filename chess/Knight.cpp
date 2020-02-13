#include "Knight.h"
#include <cmath>

Knight::Knight(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_KNIGHT : BLACK_KNIGHT) {
}

const char* Knight::getName() {
	return "KNIGHT";
}

bool Knight::canMove(BoardPiece* bp, Entity* brd) {
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	int x = abs(current.x - destination.x);
	int y = abs(current.y - destination.y);
	if ((x == 2 && y == 1) || (x == 1 && y == 2)) {
		return true;
	}
	return false;
}

bool Knight::canBeat(Figure* fig, Entity* brd) {
	if (getColor() == fig->getColor()) return false;
	if (canMove(fig->getPiece(), brd)) return true;
}