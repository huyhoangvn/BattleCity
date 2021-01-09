#include "Button.h"

Button::Button(float x, float y, 
	float width, float height, 
	sf::Font* font, std::string textString, unsigned int characterSize, sf::Color textColor,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	//Init button and button status
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(this->idleColor);
	this->buttonState = BTN_IDLE;


	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(textString);
	this->text.setFillColor(textColor);
	this->text.setCharacterSize(characterSize);
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width/2.f - this->text.getGlobalBounds().width/2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height/2.f - this->text.getGlobalBounds().height*1.5f
	);
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
	if (this->buttonState == BTN_PRESS) {
		return true;
	}
	return false;
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
	target.draw(this->text);
}

void Button::update(const sf::Vector2f mousePosition)
{
	this->buttonState = BTN_IDLE;
	/*Update the booleans for hover and press*/
	//check the bounds of the sprite in the global 2D world's coordinate system
	//whether it contain mouse or not
	if (this->shape.getGlobalBounds().contains(mousePosition)) {
		this->buttonState = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->buttonState = BTN_PRESS;
		}
	}

	switch (this->buttonState) 
	{
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;
	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;
	case BTN_PRESS:
		this->shape.setFillColor(this->activeColor);
		break;
	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}
