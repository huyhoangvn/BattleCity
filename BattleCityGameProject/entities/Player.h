#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "../builder/ThrowableBuilder.h"

class Player : 
	public Entity
{
private:

protected:
	ThrowableBuilder* throwableBuilder;

	//Init Variable
	void initVariable();

	//Init Funtions
	void initMovementComponent();
	void initAnimationComponent(sf::Texture& textureSheet);
	void initHitboxComponent();
	void initHpbarComponent();

	void initThrowableBuilder();

public:
	Player(float x, float y, sf::Texture &textureSheet);
	virtual ~Player();

	//Function
	void attack();
	void move(const DirectionState direction);
	void createThrowable(float speed, sf::Texture& textureSheet);
	void checkCollision(Entity* otherEntity, float push);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

#endif 