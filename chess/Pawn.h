#pragma once
#include "Figure.h"
#define WHITE_PAWN "res/pawn_white.png"
#define BLACK_PAWN "res/pawn_black.png"

class Pawn :
	public Figure
{
public:
	Pawn(BoardPiece*,sf::Color);
	bool canMove(BoardPiece*,Entity*) override;
	bool canBeat(Figure*, Entity*) override;
	bool firstMove = true;
	const char* getName() override;
};

