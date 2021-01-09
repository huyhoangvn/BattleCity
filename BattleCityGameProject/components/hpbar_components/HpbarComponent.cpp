#include "hpbarComponent.h"

void HpbarComponent::initVariable()
{
	this->currentHp = maxHp;
	this->visible = true;
}

HpbarComponent::HpbarComponent(
	float maxHp,
	sf::Sprite& sprite, float xOffset, float yOffset,
	float width, float height)
	: maxHp(maxHp), sprite(sprite), xOffset(xOffset), yOffset(yOffset), width(width), height(height)
{
	//Frame position and size
	this->hpbarFrame.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
	this->hpbarFrame.setSize(sf::Vector2f(width, height));
	//Frame default graphic
	this->hpbarFrame.setOutlineColor(sf::Color::Black);
	this->hpbarFrame.setOutlineThickness(1.f);
	this->hpbarFrame.setFillColor(sf::Color::Transparent);
	//Inside position and size
	this->hpbarInside.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
	this->hpbarInside.setSize(sf::Vector2f(width, height));
	//Frame default graphic
	this->hpbarInside.setFillColor(sf::Color::Red);

	this->initVariable();
}


HpbarComponent::~HpbarComponent()
{
}

const float& HpbarComponent::getCurrentHp() const
{
	return this->currentHp;
}

void HpbarComponent::changeCurrentHp(const float amount)
{
	this->currentHp += amount;
	if (this->currentHp > this->maxHp)
		this->currentHp = this->maxHp;
	if (this->currentHp < 0)
		this->currentHp = 0;
	
	float currentWidth = (this->currentHp / this->maxHp) * this->width;
	this->hpbarInside.setSize(sf::Vector2f(currentWidth, this->height));
}

void HpbarComponent::changeVisibility(const bool visible)
{
	this->visible = visible;
}

void HpbarComponent::changeOffset(const float xOffset, const float yOffset)
{
	this->xOffset = xOffset;
	this->yOffset = yOffset;
}

void HpbarComponent::changeOffset(HpbarPlacement placement)
{
	switch (placement)
	{
	case HpbarPlacement::BENEATH:
		this->yOffset = this->sprite.getGlobalBounds().height;
		this->xOffset = (this->sprite.getGlobalBounds().width - this->width)/2.f;
		break;
	case HpbarPlacement::ABOVE:
		this->yOffset = 0;
		this->xOffset = (this->sprite.getGlobalBounds().width - this->width) / 2.f;
		break;
	default:
		break;
	}
}


void HpbarComponent::update()
{
	this->hpbarFrame.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
	this->hpbarInside.setPosition(this->xOffset + this->sprite.getPosition().x, this->yOffset + this->sprite.getPosition().y);
}

void HpbarComponent::render(sf::RenderTarget& target)
{
	if (visible) {
		target.draw(this->hpbarFrame);
		target.draw(this->hpbarInside);
	}
}
