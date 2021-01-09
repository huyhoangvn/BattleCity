#ifndef ENTITY_H
#define ENTITY_H

#include "../components/movement_components/MovementComponent.h"
#include "../components/animation_components/AnimationComponent.h"
#include "../components/hitbox_components/HitboxComponent.h"
#include "../components/hpbar_components/HpbarComponent.h"

class Entity
{
private:

protected:
	sf::Sprite sprite;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;
	HitboxComponent* hitboxComponent;
	HpbarComponent* hpbarComponent;

	//Init Function
	void initVariable();
	void initComponent();
public:
	Entity();
	virtual ~Entity();

	//Component Function
	void setTexture(sf::Texture &texture);
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationComponent(sf::Texture& textureSheet);
	void createHitboxComponent(sf::Sprite& sprite, 
		float xOffset, float yOffset, float width, float height);
	void createHpbarComponent(
		float maxHp,
		sf::Sprite& sprite, float xOffset, float yOffset, 
		float width, float height);

	//Function
	virtual void setPosition(const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

#endif 