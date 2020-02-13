#include "Queen.h"
#include <memory>

Queen::Queen(BoardPiece* piece, sf::Color color) :
	Figure(piece, color, sf::Color::White == color ? WHITE_QUEEN : BLACK_QUEEN) {
}

const char* Queen::getName() {
	return "QUEEN";
}

bool Queen::canMove(BoardPiece* bp, Entity* brd) {
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	//rook or bishop moves
	//if rook moves
	std::unique_ptr<Bishop> b(new Bishop(getPiece(), getColor()));
	std::unique_ptr<Rook> r(new Rook(getPiece(), getColor()));
	return b->canMove(bp,brd) || r->canMove(bp,brd);
}

bool Queen::canBeat(Figure* fig, Entity* brd) {
	if (this->getColor() == fig->getColor()) return false;
	return canMove(fig->getPiece(), brd);
}