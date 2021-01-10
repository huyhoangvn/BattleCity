#ifndef THROWABLE_H
#define THROWABLE_H

#include "Entity.h"

class Throwable :
	public Entity
{
private:

protected:
	//Init variable
	bool visible;

	//Init Variable
	void initVariable();

	//Init Funtions
	void initMovementComponent(float speed);
	void initAnimationComponent(sf::Texture& textureSheet);
	void initHitboxComponent();
public:
	Throwable(float speed, float x, float y, sf::Texture& textureSheet);
	virtual ~Throwable();

	//Accessor
	bool& getVisible();
	void setVisible(const bool visible);

	//Function
	void attack();
	void move(const DirectionState direction);
	bool checkCollision(Entity* otherEntity, float push);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

#endif 