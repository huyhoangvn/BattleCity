#ifndef BRICK_H
#define BRICK_H

#include "Entity.h"

class Brick :
	public Entity
{
private:

protected:
	//Init variable
	bool visible;

	//Init Variable
	void initVariable();

	//Init Funtions
	void initMovementComponent();
	void initAnimationComponent(sf::Texture& textureSheet, const float width, const float height);
	void initHitboxComponent(const float width, const float height);
public:
	Brick(float x, float y, float width, float height, sf::Texture& textureSheet);
	virtual ~Brick();

	//Accessor
	bool& getVisible();
	void setVisible(const bool visible);

	//Function
	bool checkCollision(Entity* otherEntity, float push);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};


#endif 