#include "BoardPiece.h"

void BoardPiece::draw(sf::RenderTarget& targ, sf::RenderStates states) const{
	targ.draw(square, states);
}

sf::Vector2f BoardPiece::getPosition() {
	return square.getPosition();
}

sf::RectangleShape *BoardPiece::getSquare() {
	return &square;
}