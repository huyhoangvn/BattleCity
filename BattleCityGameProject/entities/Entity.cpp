#include "Entity.h"


void Entity::initVariable()
{
}

void Entity::initComponent()
{
	this->movementComponent = nullptr;
	this->animationComponent = nullptr;
	this->hitboxComponent = nullptr;
	this->hpbarComponent = nullptr;
}

Entity::Entity()
{
	this->initVariable();
	this->initComponent();
}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete this->movementComponent;
	delete this->animationComponent;
	delete this->hpbarComponent;
}

void Entity::setTexture(sf::Texture &texture)
{
	//Loading Texture take long time so ptr to prevent duplicate texture
	this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration)
{
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationComponent(sf::Texture& textureSheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, textureSheet);
}

void Entity::createHitboxComponent(sf::Sprite& sprite, 
	float xOffset, float yOffset, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, xOffset, yOffset, width, height);
}

void Entity::createHpbarComponent(float maxHp,
	sf::Sprite& sprite, float xOffset, float yOffset, 
	float width, float height)
{
	this->hpbarComponent = new HpbarComponent(maxHp, sprite, xOffset, yOffset, width, height);
}

HitboxComponent * Entity::getHitboxComponent()
{
	return this->hitboxComponent;
}

HpbarComponent * Entity::getHpbarComponent()
{
	return this->hpbarComponent;
}

MovementComponent * Entity::getMovementComponent()
{
	return this->movementComponent;
}

AnimationComponent * Entity::getAnimationComponent()
{
	return this->animationComponent;
}

void Entity::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}


