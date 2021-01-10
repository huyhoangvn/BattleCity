#ifndef HITBOX_COMPONENT_H
#define HITBOX_COMPONENT_H

#include "../../header/Dependences.h"

class HitboxComponent
{
private:

protected:

	//Variable
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	
	float xOffset;
	float yOffset;

	//Init Function
	void initVariable();

public:
	HitboxComponent(sf::Sprite& sprite, 
		float xOffset, float yOffset,
		float width, float height);
	virtual ~HitboxComponent();

	//Accessor
	sf::Vector2f getPosition();
	sf::Vector2f getHalfSize();

	bool checkCollision(HitboxComponent* otherHitbox, float push);

	//Function
	void moveHitBoxSpritePosition(const float x, const float y);

	void update();
	void render(sf::RenderTarget &target);
};

#endif 