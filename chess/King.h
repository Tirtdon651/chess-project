#pragma once
#include "Figure.h"
#define WHITE_KING "res/king_white.png"
#define BLACK_KING "res/king_black.png"

class King :
	public Figure
{
public:
	King(BoardPiece*, sf::Color);
	bool canMove(BoardPiece*, Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	const char* getName() override;
};

