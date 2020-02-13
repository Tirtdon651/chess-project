#pragma once
#include "Figure.h"
#define WHITE_KNIGHT "res/knight_white.png"
#define BLACK_KNIGHT "res/knight_black.png"

class Knight :
	public Figure
{
public:
	Knight(BoardPiece*, sf::Color);
	bool canMove(BoardPiece*, Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	const char* getName() override;
};

