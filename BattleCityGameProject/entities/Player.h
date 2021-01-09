#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : 
	public Entity
{
private:

protected:
	//Init Funtions
	void initMovementComponent();
	void initAnimationComponent(sf::Texture& textureSheet);
	void initHitboxComponent();
	void initHpbarComponent();

public:
	Player(float x, float y, sf::Texture &textureSheet);
	virtual ~Player();

	//Function
	void attack();
	void move(const DirectionState direction);

	virtual void update(const float& dt);
};

#endif 