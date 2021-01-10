#include "HitboxComponent.h"

void HitboxComponent::initVariable()
{
}

HitboxComponent::HitboxComponent(sf::Sprite& sprite,
	float xOffset, float yOffset,
	float width, float height)
	: sprite(sprite), xOffset(xOffset), yOffset(yOffset)
{
	this->hitbox.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
	this->hitbox.setSize(sf::Vector2f(width, height));
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineColor(sf::Color::Transparent);

	//Test
	/*
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
	*/

	this->initVariable();
}

HitboxComponent::~HitboxComponent()
{
}

sf::Vector2f HitboxComponent::getPosition()
{
	return hitbox.getPosition();
}

sf::Vector2f HitboxComponent::getHalfSize()
{
	return hitbox.getSize()/2.f;
}

//Test 
bool HitboxComponent::checkCollision(HitboxComponent* otherHitbox, float push)
{
	sf::Vector2f otherPosition = otherHitbox->getPosition();
	sf::Vector2f ortherHalfsize = otherHitbox->getHalfSize();
	sf::Vector2f thisPositon = this->getPosition();
	sf::Vector2f thisHalfsize = this->getHalfSize();

	float deltaX = otherPosition.x - thisPositon.x;
	float deltaY = otherPosition.y - thisPositon.y;

	float intersectX = abs(deltaX) - (ortherHalfsize.x + thisHalfsize.x);
	float intersectY = abs(deltaY) - (ortherHalfsize.y + thisHalfsize.y);

	if (intersectX < 0.f && intersectY < 0.f) {
		push = std::min(std::max(push, 0.f), 1.f);// 0 <= push <= 1

		if (intersectX > intersectY) {
			if (deltaX > 0.f) {
				this->moveHitBoxSpritePosition(intersectX * (1.f - push), 0.f);
				otherHitbox->moveHitBoxSpritePosition(-intersectX * push, 0.f);
			}
			else {
				this->moveHitBoxSpritePosition(-intersectX * (1.f - push), 0.f);
				otherHitbox->moveHitBoxSpritePosition(intersectX * push, 0.f);
			}
		}
		else {
			if (deltaY > 0.f) {
				this->moveHitBoxSpritePosition(0.f, intersectY * (1.f - push));
				otherHitbox->moveHitBoxSpritePosition(0.f, -intersectY * push);
			}
			else {
				this->moveHitBoxSpritePosition(0.f, -intersectY * (1.f - push));
				otherHitbox->moveHitBoxSpritePosition(0.f, intersectY * push);
			}
		}

		return true;
	}

	return false;
}


void HitboxComponent::moveHitBoxSpritePosition(const float x, const float y)
{
	this->sprite.move(sf::Vector2f(x, y));
}

void HitboxComponent::update()
{
	this->hitbox.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}
