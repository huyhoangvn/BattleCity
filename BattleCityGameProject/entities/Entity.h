#ifndef ENTITY_H
#define ENTITY_H

//Main include :) prevent double include
#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Entity
{
private:

protected:
	sf::RectangleShape shape;//placeholder
	float movementSpeed;
public:
	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float xDir, const float yDir);

	//Function
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif 