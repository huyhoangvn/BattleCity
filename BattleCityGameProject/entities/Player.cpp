#include "Player.h"


void Player::initVariable()
{
}

void Player::initComponent()
{
}

Player::Player(float x, float y, sf::Texture* texture)
	:Entity()
{
	this->initVariable();
	this->initComponent();
	this->createSprite(texture);
	this->setPosition(x, y);
}

Player::~Player()
{
}
