#pragma once
#include "Figure.h"
#define WHITE_BISHOP "res/bishop_white.png"
#define BLACK_BISHOP "res/bishop_black.png"

class Bishop :
	public Figure
{
public:
	Bishop(BoardPiece*, sf::Color);
	bool canMove(BoardPiece*, Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	const char* getName() override;
};

