#include "King.h"
#include <cmath>
#include "Queen.h"

King::King(BoardPiece* piece, sf::Color color) : 
	Figure(piece, color, sf::Color::White == color ? WHITE_KING : BLACK_KING) {
}

const char* King::getName() {
	return "KING";
}

bool King::canMove(BoardPiece* bp, Entity* brd) {
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	//if distance is 1 square use queens moves	
	double dist = sqrt(pow(destination.x - current.x, 2) + pow(destination.y - current.y, 2));
	if (dist != sqrt(2) && dist!=1) return false;
	std::unique_ptr<Queen> b(new Queen(getPiece(), getColor()));
	return b->canMove(bp, brd);
}

bool King::canBeat(Figure* fig, Entity* brd) {
	if (this->getColor() == fig->getColor()) return false;
	return canMove(fig->getPiece(), brd);
}