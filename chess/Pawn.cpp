#include "Pawn.h"
#include <iostream>
#include <cmath>

Pawn::Pawn(BoardPiece* piece,sf::Color color) : 
	Figure(piece, color, sf::Color::White == color ? WHITE_PAWN : BLACK_PAWN) {
	
}

const char* Pawn::getName() {
	return "PAWN";
}

bool Pawn::canMove(BoardPiece* bp, Entity* board) {
	bool white = sf::Color::White == getColor();
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = bp->getId();
	
	int dist = destination.y - current.y;
	if (!firstMove && abs(dist) > 1) return false;
	if (white && current.x == destination.x && dist > 0 && dist < 3)
	{
		firstMove = false;
		return true;
	}
	else if (!white && current.x == destination.x && dist < 0 && dist > -3)
	{
		firstMove = false;
		return true;
	}
	return false;
}

bool Pawn::canBeat(Figure* fig, Entity* board) {
	if (getColor() == fig->getColor()) return false;
	sf::Vector2i current = getPiece()->getId();
	sf::Vector2i destination = fig->getPiece()->getId();
	bool isWhite = getColor() == sf::Color::White;
	if (isWhite && (current.y + 1) == destination.y &&
		((current.x + 1) == destination.x || (current.x - 1) == destination.x)) {
		return true;
	}
	else if (!isWhite && (current.y - 1) == destination.y &&
		((current.x + 1) == destination.x || (current.x - 1) == destination.x)) {
		return true;	
	}
	return false;
}
