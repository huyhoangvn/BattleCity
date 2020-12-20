#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

//#include "../shape/RoundRectangleShape.h"

enum ButtonState {
	BTN_IDLE = 0,
	BTN_HOVER = 1,
	BTN_PRESS = 2,
};

class Button
{
private:

protected:
	//Text
	sf::Font *font;
	sf::Text text;
	//Button shape
	sf::RectangleShape shape;
	unsigned short buttonState;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y,
		float width, float height,
		sf::Font *font, std::string textString, unsigned int characterSize, sf::Color textColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	virtual ~Button();

	//Accessor
	const bool isPressed() const;

	//Function
	virtual void update(const sf::Vector2f mousePosition);
	virtual void render(sf::RenderTarget* target);
};

#endif 