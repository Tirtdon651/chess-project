#pragma once
#include "BoardPiece.h"


class Figure :
	public Entity
{
private:
	BoardPiece *piece;
	sf::Color color;
	sf::Sprite *sprite;
	sf::Texture *texture;
public:
	Figure( BoardPiece*, sf::Color, const char*);
	void moveTo(BoardPiece*);
	sf::Vector2f getPosition();
	
	sf::Color getColor();
	virtual const char* getName() = 0;
	virtual bool canMove(BoardPiece*, Entity*) = 0;
	virtual bool canBeat(Figure*, Entity*) = 0;
	BoardPiece* getPiece() {
		return piece;
	}
	sf::Sprite* getSprite() const { return sprite; }
	void setPiece(BoardPiece* b) { piece = b; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPosition(BoardPiece);
	~Figure();
};

