#pragma once
#include "SFML/Graphics.hpp"


class Entity :
	public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const override = 0;
};

