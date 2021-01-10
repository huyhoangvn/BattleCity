#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "../../header/Dependences.h"

class MovementComponent
{
private:

protected:
	//Variable
	sf::Sprite* sprite;

	DirectionState lastDirection;
	ActionState lastAction;

	float maxVelocity;

	float acceleration;
	float deceleration; 

	sf::Vector2f velocity;
	//Init Function
	void initVariable();
public:
	MovementComponent(sf::Sprite& sprite,
		float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementComponent();

	//Accessor
	const float& getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;

	//Function
	const bool getMovementState(const ActionState actionState, const DirectionState directionState = DirectionState::UNKNOWN) const;
	const bool getActionState(const ActionState actionState) const;
	const bool getDirectionState(const DirectionState actionState) const;
	const ActionState getLastAction();
	const DirectionState getLastDirection();

	void attack();
	void idle();
	void move(const DirectionState direction);

	void update(const float& dt);
};

#endif 