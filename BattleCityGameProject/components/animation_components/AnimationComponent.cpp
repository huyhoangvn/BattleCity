#include "AnimationComponent.h"

void AnimationComponent::initVariable()
{
	this->animationSequenceDone = false;
	this->lastAnimation = nullptr;
	//this->priorityAnimation = nullptr;
}

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
	: sprite(sprite), textureSheet(textureSheet)
{
	this->initVariable();
}

AnimationComponent::~AnimationComponent()
{
	for (auto &i : this->animationsMap) {
		delete i.second;
	}
}

void AnimationComponent::addAnimation(const std::string key,
	float animationTimer,
	int xStartFrame, int yStartFrame, int xFrame, int yFrame,
	int width, int height)
{
	this->animationsMap[key] = new Animation(
		this->sprite, this->textureSheet,
		animationTimer,
		xStartFrame, yStartFrame, xFrame, yFrame,
		width, height
	);
}

const bool& AnimationComponent::isFinishedAnimationSequence()
{
	return this->animationSequenceDone;
}

void AnimationComponent::play(const std::string key, const float& dt)
{
	if (this->lastAnimation != this->animationsMap[key]) {
		if (this->lastAnimation != nullptr)
			this->lastAnimation->reset();
		this->lastAnimation = this->animationsMap[key];
	}
	this->animationsMap[key]->play(dt);
	this->animationSequenceDone = animationsMap[key]->isFinishedAnimationSequence();
}

/*
void AnimationComponent::play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority)//TEST
{
	if (this->priorityAnimation) {
		if (this->priorityAnimation == this->animationsMap[key]) {
			if (this->lastAnimation != this->animationsMap[key]) {
				if (this->lastAnimation != nullptr)
					this->lastAnimation->reset();

				this->lastAnimation = this->animationsMap[key];
			}
			this->animationsMap[key]->play(dt, modifier, modifier_max);
		}
	}
	else // no priority is set  
	{
		if (priority) {
			this->priorityAnimation = this->animationsMap[key];
		}
		if (this->lastAnimation != this->animationsMap[key]) {
			if (this->lastAnimation != nullptr)
				this->lastAnimation->reset();

			this->lastAnimation = this->animationsMap[key];
		}

		//Play priority animation
		this->animationsMap[key]->play(dt, modifier, modifier_max);

		//If animation sequence is finish set priority animation to null
		if (this->animationsMap[key]->isFinishedAnimationSequence()) {
			this->priorityAnimation = nullptr;
		}
	}
}
*/

