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
	bool checkIntersect(const sf::FloatRect& frect);

	//Function
	void update();
	void render(sf::RenderTarget &target);
};

#endif 