#pragma once
#include "Figure.h"
#define WHITE_ROOK "res/rook_white.png"
#define BLACK_ROOK "res/rook_black.png"

class Rook :
	public Figure
{
public:
	Rook(BoardPiece*, sf::Color);
	bool canMove(BoardPiece*,Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	const char* getName() override;
};

