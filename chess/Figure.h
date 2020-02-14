#pragma once
#include "BoardPiece.h"


class Figure :
	public Entity
{
private:
	//board square
	BoardPiece *piece;
	//color of the figure
	sf::Color color;
	//sprite
	sf::Sprite *sprite;
	//texture of the sprite
	sf::Texture *texture;
public:
	//constructor
	//								texture of the figure
	Figure( BoardPiece*, sf::Color, const char* texture);
	//move to another square on the board
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
	//draw on the screen
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void setPosition(BoardPiece);
	~Figure();
};

