#pragma 
#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Figure.h"
#include <string>
#include "Board.h"

class Game
{
private:
	sf::RenderWindow *window;
	Background *background;
	void display();
	sf::Sprite sp;
	Board *board;
	bool onMouseClick(sf::Event);
	bool isWhiteTurn;
	bool isCheck;
	bool isGameOver();
	bool gameOver;
	void restartButtonListener(sf::Event);
	sf::Text *text;
	sf::Font *font;
public:
	Game(sf::Vector2f, std::string);
	void start();
	~Game() {
		delete window;
		delete background;
		if(board)
		delete board;
		delete font;
		delete text;
	}
};

