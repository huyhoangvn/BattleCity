#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : 
	public Entity
{
private:

protected:
	//Init Variable

	//Init Funtions
	void initVariable();
	void initComponent();
public:
	Player(float x, float y, sf::Texture *texture);
	virtual ~Player();

	//Function
};

#endif 