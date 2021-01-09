#ifndef HPBAR_COMPONENT_H
#define HPBAR_COMPONENT_H

#include "../../header/Dependences.h"

class HpbarComponent
{
private:

protected:

	//Variable
	sf::Sprite& sprite;
	sf::RectangleShape hpbarFrame;
	sf::RectangleShape hpbarInside;

	float currentHp;
	float maxHp;

	float xOffset;
	float yOffset;

	float width;
	float height;

	float visible;
	
	//Init Function
	void initVariable();

public:
	HpbarComponent(float amount,
		sf::Sprite& sprite, float xOffset, float yOffset,
		float width, float height);
	virtual ~HpbarComponent();

	//Accessor
	const float& getCurrentHp() const;

	//Function
	void changeCurrentHp(const float amount);
	void changeVisibility(const bool visible);
	void changeOffset(const float xOffset, const float yOffset);
	void changeOffset(HpbarPlacement placement);

	void update();
	void render(sf::RenderTarget &target);
};

#endif 