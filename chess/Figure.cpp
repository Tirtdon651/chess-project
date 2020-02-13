#include "Figure.h"
#include "Game.h"



Figure::Figure(BoardPiece* piece, sf::Color color, const char* texture) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile(texture);
	sprite = new sf::Sprite(*this->texture);
	this->piece = piece;
	this->color = color;
	sprite->setScale({ 0.12f,0.12f });
	setPosition(*piece);
	this->piece->setEmpty(false);
}

sf::Color Figure::getColor() {
	return color;
}

void Figure::moveTo(BoardPiece* piece) {
	this->piece->resetColor();
	this->piece->setEmpty(true);
	setPosition(*piece);
	setPiece(piece);
	this->piece->setEmpty(false);
}

void Figure::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(*sprite, states);
}

void Figure::setPosition(BoardPiece p) {
	sf::Vector2f pos = p.getPosition();
	sf::Vector2f size(sprite->getTextureRect().width * sprite->getScale().x, sprite->getTextureRect().height * sprite->getScale().y);
	sprite->setPosition({ pos.x + (BoardPiece::SQUARE_SIZE - size.x) / 2, pos.y + (BoardPiece::SQUARE_SIZE - size.y) / 2 });
}

sf::Vector2f Figure::getPosition() {
	return sprite->getPosition();
}

Figure::~Figure() {
	delete sprite;
	delete texture;
}