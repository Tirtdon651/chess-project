#pragma once
#include "Rook.h"
#include "Bishop.h"

#define WHITE_QUEEN "res/queen_white.png"
#define BLACK_QUEEN "res/queen_black.png"

class Queen :
	public Figure
{
public:
	Queen(BoardPiece*, sf::Color);
	bool canMove(BoardPiece*, Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	const char* getName() override;
};

