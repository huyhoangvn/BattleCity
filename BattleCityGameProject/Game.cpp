#include "Game.h"

//Private Function
void Game::initializeVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Title", sf::Style::Titlebar | sf::Style::Close);
}

//Constructor
Game::Game()
{
	this->initializeVariable();
	this->initWindow();
}

//Destructor
Game::~Game()
{
	delete this->window;
}

//Accessor
const bool Game::runing() const
{
	return this->window->isOpen();
}

//Fuction
void Game::updateEvent()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape) {
					this->window->close();
				}
				break;
		}
	}
}

void Game::update()
{
	this->updateEvent();
}

void Game::render()
{
	this->window->clear();

	//Draw game object

	this->window->display();
}
