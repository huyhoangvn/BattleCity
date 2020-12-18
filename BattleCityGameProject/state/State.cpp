#include "State.h"

void State::initKeybinds()
{
}

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys)
{
	this->quit = 0;
	this->supportedKeys = supportedKeys;
	this->window = window;
}

State::~State()
{
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		//Usually Escape gonna quit app so in case you change the quit keybind
		this->quit = true;
	}
}

const bool& State::getQuit() const
{
	return this->quit;
}
