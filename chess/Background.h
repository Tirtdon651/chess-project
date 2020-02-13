#pragma once
#include "Entity.h"
class Background :
	public Entity
{
private:
	sf::RectangleShape *shape;
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const override;
	Background(sf::Texture*, sf::Vector2f);
	Background(const sf::Color&, sf::Vector2f);
};

