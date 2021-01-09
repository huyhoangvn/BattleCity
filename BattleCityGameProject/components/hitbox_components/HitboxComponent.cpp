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
	//Testing
	this->hitbox.setFillColor(sf::Color::Transparent);
	this->hitbox.setOutlineThickness(1.f);
	this->hitbox.setOutlineColor(sf::Color::Green);
	
	this->initVariable();
}

HitboxComponent::~HitboxComponent()
{
}

bool HitboxComponent::checkIntersect(const sf::FloatRect& frect)
{
	return this->hitbox.getGlobalBounds().intersects(frect);
}

void HitboxComponent::update()
{
	this->hitbox.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
}

void HitboxComponent::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox);
}
