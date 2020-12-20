#include "Entity.h"


void Entity::initVariable()
{
	this->texture = nullptr;
	this->sprite = nullptr; 
	this->movementSpeed = 200;
}

Entity::Entity()
{
	this->initVariable();
}

Entity::~Entity()
{
	delete this->sprite;
	//Texture is from outside
}

void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}

void Entity::move(const float& dt, const float xDir, const float yDir)
{
	if (this->sprite) {
		this->sprite->move(xDir * movementSpeed * dt, yDir * movementSpeed * dt);
	}
}


void Entity::setPosition(const float x, const float y)
{
	if (this->sprite) {
		this->sprite->setPosition(x, y);
	}
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget* target)
{
	if (this->sprite) {
		target->draw(*this->sprite);
	}
}
