#include "Brick.h"

void Brick::initVariable()
{
	this->visible = true;
}

void Brick::initMovementComponent()
{
	this->createMovementComponent(0, 0.f, 0.f);
}

void Brick::initAnimationComponent(sf::Texture& textureSheet, const float width, const float height)
{
	this->createAnimationComponent(textureSheet);
	this->animationComponent->addAnimation("IDLE", 0.f, 0, 0, 0, 0, (int)width, (int)height);
}

void Brick::initHitboxComponent(const float width, const float height)
{
	this->createHitboxComponent(this->sprite, 0.f, 0.f, width, height);
}

Brick::Brick(float x, float y, float width, float height, sf::Texture& textureSheet)
	:Entity()
{
	this->setPosition(x, y);

	this->initVariable();

	this->initMovementComponent();

	this->initAnimationComponent(textureSheet, width, height);

	this->initHitboxComponent( width, height);
}

Brick::~Brick()
{
}

bool& Brick::getVisible()
{
	return this->visible;
}

void Brick::setVisible(const bool visible)
{
	this->visible = visible;
}

bool Brick::checkCollision(Entity* otherEntity, float push)
{
	if (otherEntity != nullptr) {
		HitboxComponent* otherHitbox = otherEntity->getHitboxComponent();
		if (otherHitbox != nullptr) {
			if (this->hitboxComponent->checkCollision(otherHitbox, push)) {
				//Test
				return true;
			}
		}
	}
	return false;
}

void Brick::update(const float& dt)
{
	this->movementComponent->update(dt);
	if (this->movementComponent->getActionState(ActionState::IDLE)) {
		this->animationComponent->play("IDLE", dt);
	}

	//Test
	this->hitboxComponent->update();
}

void Brick::render(sf::RenderTarget& target)
{
	if (visible) {
		target.draw(this->sprite);

		if (this->hitboxComponent) {
			this->hitboxComponent->render(target);
		}
	}
}

