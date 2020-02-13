#include "Background.h"

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(*shape);
}

Background::Background(sf::Texture *texture, sf::Vector2f size) {
	shape = new sf::RectangleShape();
	shape->setTexture(texture);
	shape->setSize(size);
}

Background::Background(const sf::Color &color, sf::Vector2f size) {
	shape = new sf::RectangleShape();
	shape->setFillColor(color);
	shape->setSize(size);
}
        
