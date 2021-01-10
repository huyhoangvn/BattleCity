#include "Throwable.h"

void Throwable::initVariable()
{
	this->visible = false;
}

void Throwable::initMovementComponent(float speed)
{
	this->createMovementComponent(speed, 50.f, 25.f);
}

void Throwable::initAnimationComponent(sf::Texture& textureSheet)
{
	this->createAnimationComponent(textureSheet);
	this->animationComponent->addAnimation("MOVE", 10.f, 0, 0, 3, 0, 32, 26);
	this->animationComponent->addAnimation("ATK", 10.f, 0, 1, 3, 1, 32, 26);

}

void Throwable::initHitboxComponent()
{
	this->createHitboxComponent(this->sprite, 6.f, 4.f, 20, 20);
}

Throwable::Throwable(float speed, float x, float y, sf::Texture& textureSheet)
	:Entity()
{
	this->setPosition(x, y);

	this->initVariable();

	this->initMovementComponent(speed);

	this->initAnimationComponent(textureSheet);

	this->initHitboxComponent();
}

Throwable::~Throwable()
{
}

bool& Throwable::getVisible()
{
	return this->visible;
}

void Throwable::setVisible(const bool visible)
{
	this->visible = visible;
}

void Throwable::attack()
{
	this->movementComponent->attack();
}

void Throwable::move(const DirectionState direction)
{
	this->movementComponent->move(direction);
	this->visible = true;
}

bool Throwable::checkCollision(Entity* otherEntity, float push)
{
	if (otherEntity != nullptr) {
		HitboxComponent* otherHitbox = otherEntity->getHitboxComponent();
		if (otherHitbox != nullptr) {
			if (this->hitboxComponent->checkCollision(otherHitbox, push)) {
				//Test
				this->attack();
				return true;
			}
		}
	}
	return false;
}

void Throwable::update(const float& dt)
{
	this->movementComponent->update(dt);
	if (this->movementComponent->getActionState(ActionState::ATK)) {
		this->animationComponent->play("ATK", dt);
	
		if (this->animationComponent->isFinishedAnimationSequence()) {
			this->movementComponent->idle();
			this->visible = false;
		}
	}
	else if (this->movementComponent->getActionState(ActionState::MOVE)) {
		this->animationComponent->play("MOVE", dt);
	}

	//Test
	this->hitboxComponent->update();
}

void Throwable::render(sf::RenderTarget& target)
{
	if (visible) {
		target.draw(this->sprite);

		if (this->hitboxComponent) {
			this->hitboxComponent->render(target);
		}
	}
}





