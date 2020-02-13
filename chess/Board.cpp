#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"

Board::Board(sf::Vector2f intial_pos) {
	bool white = true;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {
			sf::Color color;
			if (white) {
				color = sf::Color(76, 76, 79);
			}
			else {
				color = sf::Color(156, 89, 22);
			}
			white = !white;
			boardPieces[i][j] = new BoardPiece(color, { (float)i,(float)j });
		}
		white = !white;
	}
	reset();
}

Figure* Board::getFigure(const char* name, sf::Color color) {
	if (color == sf::Color::White) {
		for(Figure* f : whiteFigures) {
			if (f->getName() == name) return f;
		}
	}
	else if (color == sf::Color::Black) {
		for (Figure* f : blackFigures) {
			if (f->getName() == name) return f;
		}
	}
	return NULL;
}

void Board::draw(sf::RenderTarget& targ, sf::RenderStates states) const {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boardPieces[i][j]->draw(targ, states);
		}
	}
	for (int i = 0; i < whiteFigures.size(); i++) {
		whiteFigures.at(i)->draw(targ, states);
	}
	for (int i = 0; i < blackFigures.size(); i++) {
		blackFigures.at(i)->draw(targ, states);
	}
}

BoardPiece* Board::getBoardPiece(int i, int j) {
	return boardPieces[i][j];
}

Figure* Board::getFigureFromPosition(sf::Vector2f pos) {
	Figure *fig;
	for (int i = 0; i < whiteFigures.size(); i++) {
		fig = whiteFigures.at(i);
		if (fig->getPiece()->getSquare()->getGlobalBounds().contains(pos)) {
			return fig;
		}
	}
	for (int i = 0; i < blackFigures.size(); i++) {
		fig = blackFigures.at(i);
		if (fig->getPiece()->getSquare()->getGlobalBounds().contains(pos)) {
			return fig;
		}
	}
	return NULL;
}

BoardPiece* Board::getBoardPieceFromPosition(sf::Vector2f pos) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (boardPieces[i][j]->getSquare()->getGlobalBounds().contains(pos)) {
				return boardPieces[i][j];
			}
		}
	}
	return NULL;
}

void Board::reset() {
	whiteFigures.clear();
	blackFigures.clear();
	//adding pawns to the board
	for (int i = 0; i < 8; i++) {
		whiteFigures.push_back(new Pawn(boardPieces[i][1], sf::Color::White));
		blackFigures.push_back(new Pawn(boardPieces[i][6], sf::Color::Black));
	}
	//adding rooks
	whiteFigures.push_back(new Rook(boardPieces[0][0], sf::Color::White));
	whiteFigures.push_back(new Rook(boardPieces[7][0], sf::Color::White));
	blackFigures.push_back(new Rook(boardPieces[0][7], sf::Color::Black));
	blackFigures.push_back(new Rook(boardPieces[7][7], sf::Color::Black));


	//adding knights
	whiteFigures.push_back(new Knight(boardPieces[1][0], sf::Color::White));
	whiteFigures.push_back(new Knight(boardPieces[6][0], sf::Color::White));
	blackFigures.push_back(new Knight(boardPieces[1][7], sf::Color::Black));
	blackFigures.push_back(new Knight(boardPieces[6][7], sf::Color::Black));
	

	//adding bishops
	whiteFigures.push_back(new Bishop(boardPieces[2][0], sf::Color::White));
	whiteFigures.push_back(new Bishop(boardPieces[5][0], sf::Color::White));
	blackFigures.push_back(new Bishop(boardPieces[2][7], sf::Color::Black));
	blackFigures.push_back(new Bishop(boardPieces[5][7], sf::Color::Black));


	//adding queens
	whiteFigures.push_back(new Queen(boardPieces[3][0], sf::Color::White));
	blackFigures.push_back(new Queen(boardPieces[4][7], sf::Color::Black));

	//adding kings
	whiteFigures.push_back(new King(boardPieces[4][0], sf::Color::White));
	blackFigures.push_back(new King(boardPieces[3][7], sf::Color::Black));

}

void Board::clearSelelctedFig() {
	selected = false;
	selectedFig->getPiece()->resetColor();
	selectedFig = NULL;
}

void Board::removeFigure(Figure* fig) {
	if (fig->getColor() == sf::Color::White) {
		for (int i = 0; i < whiteFigures.size(); i++) {
			if (whiteFigures.at(i) == fig) {
				fig->getPiece()->setEmpty(true);
				whiteFigures.erase(whiteFigures.begin() + i);
			}
		}
	}
	else {
		for (int i = 0; i < blackFigures.size(); i++) {
			if (blackFigures.at(i) == fig) {
				fig->getPiece()->setEmpty(true);
				blackFigures.erase(blackFigures.begin() + i);
			}
		}
	}
}

Board::~Board() {
}

bool Board::isCheck(bool white) {
	if(!white)
		for (Figure *fig : whiteFigures) {
			if (fig->canBeat(blackFigures.back(), this))
				return true;
		}
	else
		for (Figure *fig : blackFigures) {
			if (fig->canBeat(whiteFigures.back(), this))
				return true;
		}
	
	return false;
}

