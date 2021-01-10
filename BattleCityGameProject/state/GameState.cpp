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
	if (!this->texture["THROWABLE_ANIMATION"].loadFromFile("resources/images/sprites/throwable/throwable_move_crash.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD THROWABLE TEXTURE");
	}
	if (!this->texture["BOUND_HORIZONTAL"].loadFromFile("resources/images/sprites/environment/Bound_horizontal.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD BOUNDER TEXTURE");
	}
	if (!this->texture["BOUND_VERTICAL"].loadFromFile("resources/images/sprites/environment/Bound_vertical.png")) {
		throw("ERROR::STATE::GAME_STATE::COULD NOT LOAD BOUNDER TEXTURE");
	}
}

void GameState::initBackground()
{

	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("resources/images/backgrounds/gamestate_background.png")) {
		throw("ERROR::STATE::MAINMENU:: COULD NOT LOAD BACK GROUND IMAGE");
	}
	this->backgroundTexture.setSmooth(true);
	this->background.setTexture(&this->backgroundTexture);
}

void GameState::initPlayer()
{
	this->player1 = new Player(
		this->window->getSize().x * 2.f/3.f, this->window->getSize().y / 2.f,
		this->texture.at("PLAYER1_ANIMATION")
	);

	this->player1->createThrowable(270.f, texture.at("THROWABLE_ANIMATION"));

	this->player2 = new Player(
		this->window->getSize().x /3.f, this->window->getSize().y / 2.f,
		this->texture.at("PLAYER2_ANIMATION")
	);

	this->player2->createThrowable(270.f, texture.at("THROWABLE_ANIMATION"));

	//AABB work poorly on 2 object with large different in size that why i have to x2 bound
	this->boundAbove = new Brick(0, 0, this->window->getSize().x * 2.f, 20, 
		this->texture.at("BOUND_HORIZONTAL"));

	this->boundBeneath = new Brick(0, this->window->getSize().y * 1.f - 20 , (float)this->window->getSize().x * 2.f, 20,
		this->texture.at("BOUND_HORIZONTAL"));

	this->boundLeft = new Brick(0, 0, 20, this->window->getSize().y * 2.f, 
		this->texture.at("BOUND_VERTICAL"));

	this->boundRight = new Brick(this->window->getSize().x * 1.f - 20, 0, 20, this->window->getSize().y * 2.f,
		this->texture.at("BOUND_VERTICAL"));

}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int> *supportedKeys, std::stack<State*> *states)
	:State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTexture();
	this->initPlayer();
	this->initBackground();
}

GameState::~GameState()
{
	delete this->player1;
	delete this->player2;
	delete this->boundAbove;
	delete this->boundBeneath;
	delete this->boundLeft;
	delete this->boundRight;
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

	//Player 1
	this->updateInput(dt);
	
	this->player1->checkCollision(boundAbove, 0.f);
	this->player1->checkCollision(boundBeneath, 0.f);
	this->player1->checkCollision(boundLeft, 0.f);
	this->player1->checkCollision(boundRight, 0.f);	
	this->player1->checkCollision(player2, 0.f);
	this->player1->update(dt);

	//Player 2
	this->player2->checkCollision(boundAbove, 0.f);
	this->player2->checkCollision(boundBeneath, 0.f);
	this->player2->checkCollision(boundLeft, 0.f);
	this->player2->checkCollision(boundRight, 0.f);
	this->player2->checkCollision(player1, 0.f);
	this->player2->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	//if dont have target then render window
	target->draw(this->background);

	this->boundAbove->render(*target);
	this->boundBeneath->render(*target);
	this->boundLeft->render(*target);
	this->boundRight->render(*target);

	this->player1->render(*target);
	this->player2->render(*target);
}
 