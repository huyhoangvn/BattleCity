#include "GameState.h"

void GameState::initKeybinds()
{
	this->getKeybindsConfig("config/gamestate_keys.ini");
}

void GameState::initTexture()
{
	if (!this->texture["PLAYER1_ANIMATION"].loadFromFile("resources/images/sprites/player/old_man_move_atk.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD PLAYER1 TEXTURE");
	}
	if (!this->texture["PLAYER2_ANIMATION"].loadFromFile("resources/images/sprites/player/glass_man_move_atk.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD PLAYER2 TEXTURE");
	}
}

void GameState::initPlayer()
{
	this->player1 = new Player(
		this->window->getSize().x * 2.f/3.f, this->window->getSize().y / 2.f,
		this->texture.at("PLAYER1_ANIMATION")
	);
	this->player2 = new Player(
		this->window->getSize().x /3.f, this->window->getSize().y / 2.f,
		this->texture.at("PLAYER2_ANIMATION")
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
	delete this->player1;
	delete this->player2;
}

void GameState::updatePlayerInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->endState();
	}
	//Player 1 input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P1_MOVE_UP")))) {
		this->player1->move(DirectionState::UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P1_MOVE_LEFT")))) {
		this->player1->move(DirectionState::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P1_MOVE_DOWN")))) {
		this->player1->move(DirectionState::DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P1_MOVE_RIGHT")))) {
		this->player1->move(DirectionState::RIGHT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P1_ATK")))) {
		this->player1->attack();
	}
	//Player 2 input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P2_MOVE_UP")))) {
		this->player2->move(DirectionState::UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P2_MOVE_LEFT")))) {
		this->player2->move(DirectionState::LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P2_MOVE_DOWN")))) {
		this->player2->move(DirectionState::DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P2_MOVE_RIGHT")))) {
		this->player2->move(DirectionState::RIGHT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("P2_ATK")))) {
		this->player2->attack();
	}
}

void GameState::updateInput(const float& dt)
{
	this->updatePlayerInput();
}

void GameState::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->player1->update(dt);
	this->player2->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	//if dont have target then render window
	this->player1->render(*target);
	this->player2->render(*target);
}
 