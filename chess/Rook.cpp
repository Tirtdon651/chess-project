#include "Rook.h"
#include <iostream>
#include "Board.h"

Rook::Rook(BoardPiece* piece, sf::Color color) : 
	Figure(piece, color,sf::Color::White == color ? WHITE_ROOK : BLACK_ROOK) {
}

const char* Rook::getName() {
	return "ROOK";
}

bool Rook::canMove(BoardPiece* bp,Entity* b) {
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	Board *board = dynamic_cast<Board*>(b);
	//legal rook move
	if (current.x == destination.x ) {
		//next check for obstacles on the way
		int i = current.y > destination.y ? destination.y : current.y;
		int max = current.y > destination.y ? current.y : destination.y;
		i++;
		for (i; i < max; i++) {
			if (!board->getBoardPiece(current.x,i)->isEmpty()) {
				return false;
			}
		}
		return true;
	}
	else if (current.y == destination.y) {
		//next check for obstacles on the way
		int i = current.x > destination.x ? destination.x : current.x;
		int max = current.x > destination.x ? current.x : destination.x;
		i++;
		for (i; i < max - 1; i++) {
			if (!board->getBoardPiece(i,current.y)->isEmpty()) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Rook::canBeat(Figure* fig, Entity* b) {
	if (this->getColor() == fig->getColor()) return false;
	return canMove(fig->getPiece(), b);
}
