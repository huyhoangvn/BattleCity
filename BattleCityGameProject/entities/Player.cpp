#include "Player.h"

void Player::initMovementComponent()
{
	this->createMovementComponent(150.f, 50.f, 25.f);
}

void Player::initAnimationComponent(sf::Texture& textureSheet)
{
	this->createAnimationComponent(textureSheet);
	this->animationComponent->addAnimation("WALK_DOWN", 10.f, 0, 0, 3, 0, 32, 48);
	this->animationComponent->addAnimation("WALK_LEFT", 10.f, 0, 1, 3, 1, 32, 48);
	this->animationComponent->addAnimation("WALK_RIGHT", 10.f, 0, 2, 3, 2, 32, 48);
	this->animationComponent->addAnimation("WALK_UP", 10.f, 0, 3, 3, 3, 32, 48);
	this->animationComponent->addAnimation("IDLE_DOWN", 10.f, 0, 4, 1, 4, 32, 48);
	this->animationComponent->addAnimation("ATK_DOWN", 10.f, 0, 5, 5, 5, 32, 48);

}

void Player::initHitboxComponent()
{
	this->createHitboxComponent(this->sprite, 3.f, 10.f, 26, 34);
}

void Player::initHpbarComponent()
{
	this->createHpbarComponent(100, this->sprite, 0.f, 0.f, 26, 5);
	this->hpbarComponent->changeOffset(HpbarPlacement::ABOVE);
}

Player::Player(float x, float y, sf::Texture& textureSheet)
	:Entity()
{
	this->setPosition(x, y);

	this->initMovementComponent();

	this->initAnimationComponent(textureSheet);

	this->initHitboxComponent();

	this->initHpbarComponent();
}

Player::~Player()
{
}

void Player::attack()
{
	this->movementComponent->attack();
}

void Player::move(const DirectionState direction)
{
	this->movementComponent->move(direction);
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt);

	//Test
	this->hpbarComponent->changeOffset(HpbarPlacement::ABOVE);

	if (this->movementComponent->getActionState(ActionState::IDLE)) {
		this->animationComponent->play("IDLE_DOWN", dt);
	}
	else if (this->movementComponent->getActionState(ActionState::ATK)) {
		this->animationComponent->play("ATK_DOWN", dt);
		if (this->animationComponent->isFinishedAnimationSequence()) {
			this->movementComponent->idle();
		}
	}
	else if(this->movementComponent->getMovementState(ActionState::MOVE, DirectionState::LEFT)){
		this->animationComponent->play("WALK_LEFT", dt);
	}
	else if (this->movementComponent->getMovementState(ActionState::MOVE, DirectionState::RIGHT)){
		this->animationComponent->play("WALK_RIGHT", dt);
	}
	else if (this->movementComponent->getMovementState(ActionState::MOVE, DirectionState::UP)){
		this->animationComponent->play("WALK_UP", dt);
		//Test
		this->hpbarComponent->changeOffset(HpbarPlacement::BENEATH);
	}
	else if (this->movementComponent->getMovementState(ActionState::MOVE, DirectionState::DOWN)) {
		this->animationComponent->play("WALK_DOWN", dt);
	}

	//Test
	this->hpbarComponent->changeCurrentHp(-1);

	this->hitboxComponent->update();
	this->hpbarComponent->update();
}




