#include "State.h"

State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State*> *states)
{
	this->quit = 0;
	this->supportedKeys = supportedKeys;
	this->window = window;
	this->states = states;
}

State::~State()
{
}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}

void State::getKeybindsConfig(std::string iniFileName)
{
	std::ifstream ifs(iniFileName);
	if (ifs.is_open()) {
		std::string key = "";
		std::string refKey = "";
		while (ifs >> key >> refKey) {
			this->keybinds[key] = this->supportedKeys->at(refKey);
		}
	}

	ifs.close();
}

void State::updateMousePosition()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
