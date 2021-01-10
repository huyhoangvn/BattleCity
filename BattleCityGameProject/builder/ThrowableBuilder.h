#ifndef THROWABLE_BUILDER_H
#define THROWABLE_BUILDER_H

#include "../entities/Throwable.h"

class ThrowableBuilder :
	public Entity
{
private:

protected:
	//Init Variable
	Throwable* throwable;
	Entity* owner;
	unsigned int storageSize;

	//Init Funtions
	void initVariable();
public:
	ThrowableBuilder(Entity* owner);
	virtual ~ThrowableBuilder();

	//Function
	bool checkCollision(Entity* otherEntity, float push);
	void createThrowable(float speed, sf::Texture& textureSheet);
	void moveThrowable();

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};


#endif 