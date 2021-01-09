#include "MovementComponent.h"

void MovementComponent::initVariable()
{
	this->lastDirection = DirectionState::DOWN;
	this->lastAction = ActionState::IDLE;
}

MovementComponent::MovementComponent(sf::Sprite& sprite,
	float maxVelocity, float acceleration, float deceleration)
{
	this->sprite = &sprite;
	this->maxVelocity = maxVelocity;
	this->acceleration = acceleration;
	this->deceleration = deceleration;

	this->initVariable();
}

MovementComponent::~MovementComponent()
{
	
}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const float& MovementComponent::getMaxVelocity() const
{
	return this->maxVelocity;
}

const bool MovementComponent::getMovementState(const ActionState actionState, const DirectionState directionState) const
{
	return this->getActionState(actionState) && this->getDirectionState(directionState);
}

const bool MovementComponent::getActionState(const ActionState actionState) const
{
	switch (actionState)
	{
	case ActionState::IDLE:
		if(this->velocity.x == 0 && this->velocity.y == 0 && this->lastAction == ActionState::IDLE)
			return true;
		break;
	case ActionState::ATK:
		if (this->velocity.x == 0 && this->velocity.y == 0 && this->lastAction == ActionState::ATK)
			return true;
		break;
	case ActionState::MOVE:
		if (this->velocity.x != 0 || this->velocity.y != 0)
			return true;
		break;
	default:
		break;
	}
	return false;
}

const bool MovementComponent::getDirectionState(const DirectionState directionState) const
{
	if (this->lastDirection == directionState)
		return true;
	return false;
}

void MovementComponent::move(const DirectionState direction)
{
	if (this->lastAction != ActionState::IDLE)
		return;

	short int xDir = 0;
	short int yDir = 0;
	switch (direction)
	{
	case DirectionState::LEFT:
		xDir = -1;
		yDir = 0;
		break;
	case DirectionState::RIGHT:
		xDir = 1;
		yDir = 0;
		break;
	case DirectionState::UP:
		xDir = 0;
		yDir = -1;
		break;
	case DirectionState::DOWN:
		xDir = 0;
		yDir = 1;
		break;
	default:
		break;
	}

	this->velocity.x += this->acceleration * xDir;
	this->velocity.y += this->acceleration * yDir;

	this->lastDirection = direction;
}

void MovementComponent::attack()
{
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->lastAction = ActionState::ATK;
}

void MovementComponent::idle()
{
	this->velocity.x = 0;
	this->velocity.y = 0;
	this->lastAction = ActionState::IDLE;
}


void MovementComponent::update(const float& dt)
{
	/*
	Deceleration the sprite and control the maximum velocity	
	Move the sprite
	*/

	//Check x
	if (this->velocity.x > 0.f) {
		//Max Velocity check
		if (this->velocity.x > this->maxVelocity) {
			this->velocity.x = this->maxVelocity;
		}
		//Decelerate x pos negative
		this->velocity.x -= this->deceleration;
		if (this->velocity.x < 0.f) {
			this->velocity.x = 0.f;
		}
	}//Check for right
	else if (this->velocity.x < 0.f) {
		//Max Velocity check
		if (this->velocity.x < -this->maxVelocity) {
			this->velocity.x = -this->maxVelocity;
		}
		//Decelerate x pos positive
		this->velocity.x += this->deceleration;
		if (this->velocity.x > 0.f) {
			this->velocity.x = 0.f;
		}
	}//Check for left

	//Check y
	if (this->velocity.y > 0.f) {
		//Max Velocity check
		if (this->velocity.y > this->maxVelocity) {
			this->velocity.y = this->maxVelocity;
		}
		//Decelerate y pos negative
		this->velocity.y -= this->deceleration;
		if (this->velocity.y < 0.f) {
			this->velocity.y = 0.f;
		}
	}//Check for right
	else if (this->velocity.y < 0.f) {
		//Max Velocity check
		if (this->velocity.y < -this->maxVelocity) {
			this->velocity.y = -this->maxVelocity;
		}
		//Decelerate y pos positive
		this->velocity.y += this->deceleration;
		if (this->velocity.y > 0.f) {
			this->velocity.y = 0.f;
		}
	}//Check for left

	//final move 
	this->sprite->move(this->velocity * dt);
}




