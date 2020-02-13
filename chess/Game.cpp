#include "Game.h"
#include "Pawn.h"
#include <iostream>
#include "King.h"

Game::Game(sf::Vector2f size, std::string title) {
	window = new sf::RenderWindow(sf::VideoMode(size.x,size.y), title, sf::Style::Titlebar | sf::Style::Close);
	background = new Background(sf::Color::Black, size);
	
	sf::err().rdbuf(NULL);
	
	font = new sf::Font();
	font->loadFromFile("fonts/AGENCYB.TTF");
	text = new sf::Text();
	text->setFont(*font);
	text->setCharacterSize(30);
	text->setString("\t\tGAME OVER\nPRESS TO RESTART");
	text->setFillColor(sf::Color::Red);
	text->setPosition((window->getSize().x - text->getLocalBounds().width ) / 2, (window->getSize().y / 2 - text->getLocalBounds().height / 2));
	
}

void Game::start() {
	board = new Board(sf::Vector2f(0, 0));
	isWhiteTurn = true;
	gameOver = false;
	isCheck = false;
	board->reset();
	while (window->isOpen()) {
		sf::Event event;
		
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (!gameOver) {
					onMouseClick(event);
					if (isCheck = board->isCheck(isWhiteTurn))
						if (!isWhiteTurn)
							std::cout << "CHECK FOR BLACK\n";
						else
							std::cout << "CHECK FOR WHITE\n";
					gameOver = isGameOver();
				}
				else {
					restartButtonListener(event);
				}
			}
			
			if (event.type == sf::Event::Resized) {

			}
		}
		display();
	}
}

void Game::restartButtonListener(sf::Event event) {
	sf::Vector2f pos({ (float)event.mouseButton.x,(float)event.mouseButton.y });
	if (text->getGlobalBounds().contains(pos)) {
		start();
	}
}
bool Game::isGameOver() {
	King *whiteKing = dynamic_cast<King*>(board->getWhiteFigures().back());
	King *blackKing = dynamic_cast<King*>(board->getBlackFigures().back());
	if (!whiteKing) {
		std::cout << "BLACK WON\n";
		return true;
	}
	else if (!blackKing) {
		std::cout << "WHITE WON\n";
		return true;
	}
	else return false;

	

	delete whiteKing, blackKing;
	return false;
}

bool Game::onMouseClick(sf::Event event) {
		sf::Vector2f pos({ (float)event.mouseButton.x,(float)event.mouseButton.y });
	//select a move
	if (board->hasSelected()) {
		Figure* figure = board->getSelectedFig();
		BoardPiece* bp = board->getBoardPieceFromPosition(pos);
		if (figure->getPiece() == bp) {
			board->clearSelelctedFig();
			std::cout << "Figure deselected\n";
		}
		else if (bp->isEmpty() && figure->canMove(bp, board)) {
			figure->moveTo(bp);
			isWhiteTurn = !isWhiteTurn;
			board->clearSelelctedFig();
			const char* color = figure->getColor() == sf::Color::White ? "White " : "Black ";
			std::cout << color << figure->getName() << " moved\n";	
		}
		else if (!bp->isEmpty()) {
			Figure *destFig = board->getFigureFromPosition(bp->getPosition());
			if (figure->canBeat(destFig, board)) {
				board->removeFigure(destFig);
				figure->moveTo(destFig->getPiece());
				isWhiteTurn = !isWhiteTurn;
				board->clearSelelctedFig();
			}
		}

	}
	//select a figure
	else {
		Figure *fig = board->getFigureFromPosition(pos);
		if (fig != NULL) {
			if ((fig->getColor() == sf::Color::White && isWhiteTurn) ||
				(fig->getColor() == sf::Color::Black && !isWhiteTurn)) {
				fig->getPiece()->getSquare()->setFillColor(sf::Color::Red);
				board->setSelectedFig(fig);
				const char* color = fig->getColor() == sf::Color::White ? "White " : "Black ";
				std::cout << color << fig->getName() << " selected\n";
				return true;
			}
			else {
				std::cout << "No figure selected!" << std::endl;

				return false;
			}
		}
	}
}

void Game::display() {
	window->clear();
	window->draw(*background);
	window->draw(*board);
	if (gameOver) {
		window->draw(*text);
	}
	window->display();
}


