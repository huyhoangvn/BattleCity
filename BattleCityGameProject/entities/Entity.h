#ifndef ENTITY_H
#define ENTITY_H

//chain include :) prevent double include
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
	//Loading Texture take long time so ptr to prevent duplicate texture
	sf::Texture *texture;
	sf::Sprite *sprite;
	float movementSpeed;
	//Init Function
	void initVariable();
public:
	Entity();
	virtual ~Entity();

	//Component Function
	virtual void createSprite(sf::Texture* texture);

	//Function
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float xDir, const float yDir);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};

#endif 