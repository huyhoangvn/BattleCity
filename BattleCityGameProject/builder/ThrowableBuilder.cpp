#include "ThrowableBuilder.h"

void ThrowableBuilder::initVariable()
{
	this->throwable = nullptr;
	this->storageSize = 0;
}

ThrowableBuilder::ThrowableBuilder(Entity* owner)
	: owner(owner)
{
	this->initVariable();
}

ThrowableBuilder::~ThrowableBuilder()
{
	delete this->throwable;
}

bool ThrowableBuilder::checkCollision(Entity* otherEntity, float push)
{
	if (this->throwable) {
		if (this->throwable->getVisible()) {
			return this->throwable->checkCollision(otherEntity, push);
		}
	}
	return false;
}

void ThrowableBuilder::createThrowable(float speed, sf::Texture& textureSheet)
{
	this->throwable = new Throwable(speed, 0, 0, textureSheet);
}

void ThrowableBuilder::moveThrowable()
{
	if (this->throwable) {
		MovementComponent* ownerMove = this->owner->getMovementComponent();
		if (ownerMove != nullptr) {
			this->throwable->move(ownerMove->getLastDirection());
		}
	}
}

void ThrowableBuilder::update(const float& dt)
{
	if (this->throwable) {
		if (this->throwable->getVisible()) {
			this->moveThrowable();
		}
		else {
			HitboxComponent* ownerHitbox = this->owner->getHitboxComponent();
			if (ownerHitbox) {
				this->throwable->setPosition(
					ownerHitbox->getPosition().x,
					ownerHitbox->getPosition().y);
			}
		}
		this->throwable->update(dt);
	}
}

void ThrowableBuilder::render(sf::RenderTarget& target)
{
	if (this->throwable) {
		this->throwable->render(target);
	}
}
