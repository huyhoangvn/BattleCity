#include "GameState.h"

void GameState::initKeybinds()
{
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int> *supportedKeys)
	:State(window, supportedKeys)
{
	this->initKeybinds();
}

GameState::~GameState()
{
	
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();
	this->updatePlayerInput(dt);
}

void GameState::updatePlayerInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player.move(dt, 0, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player.move(dt, -1.f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(dt, 0, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player.move(dt, 1.f, 0);
	}
}

void GameState::endState()
{
	std::cout << "Ending this game state\n";
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);
	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	//if dont have target then render window
	this->player.render(target);
}
 