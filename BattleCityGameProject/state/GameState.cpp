#include "GameState.h"

void GameState::initKeybinds()
{
	this->getKeybindsConfig("config/gamestate_keys.ini");
}

void GameState::initTexture()
{
	if (!this->texture["PLAYER_IDLE"].loadFromFile("resources/images/sprites/player/test.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD PLAYER_IDLE TEXTURE");
	}
}

void GameState::initPlayer()
{
	this->player = new Player(
		this->window->getSize().x / 2.f, this->window->getSize().y / 2.f,
		&this->texture.at("PLAYER_IDLE")
	);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int> *supportedKeys, std::stack<State*> *states)
	:State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initPlayer();
}

GameState::~GameState()
{
	
}

void GameState::updateInput(const float& dt)
{
	this->updatePlayerInput(dt);
}

void GameState::updatePlayerInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player->move(dt, 0, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player->move(dt, -1.f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player->move(dt, 0, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player->move(dt, 1.f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->endState();
	}
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	//if dont have target then render window
	this->player->render(target);
}
 