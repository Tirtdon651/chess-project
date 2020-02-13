#include "SFML/Graphics.hpp"
#include "Background.h"
#include "Game.h"

#define WINDOW_SIZE_X 400
#define WINDOW_SIZE_Y 400

int main() {
	Game game({ WINDOW_SIZE_X,WINDOW_SIZE_Y }, "Chess");
	game.start();
}