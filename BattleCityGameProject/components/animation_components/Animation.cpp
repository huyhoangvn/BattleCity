#include "Animation.h"

void Animation::initVariable()
{
	this->animationSequenceDone = false;
	this->timer = 0.f;
}

Animation::Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
	float animationTimer,
	int xStartFrame, int yStartFrame, int xFrame, int yFrame, 
	int width, int height)
	: sprite(sprite), textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
{
	this->startRec = sf::IntRect(xStartFrame * width, yStartFrame * height, width, height);
	this->endRec = sf::IntRect(xFrame * width, yFrame * height, width, height);

	this->sprite.setTexture(this->textureSheet, true);
	this->sprite.setTextureRect(this->startRec);
	this->currentRect = startRec;

	this->initVariable();
}

Animation::~Animation()
{
}
 
const bool& Animation::isFinishedAnimationSequence()
{
	return this->animationSequenceDone;
}

void Animation::play(const float& dt)
{
	this->animationSequenceDone = false;
	this->timer += 100.f * dt;
	//Update time
	if (this->timer >= this->animationTimer) {
		//reset timer
		this->timer = 0.f;

		if (this->currentRect != this->endRec) {
			this->currentRect.left += this->width;
		}
		else {
			this->currentRect.left = this->startRec.left;
			this->animationSequenceDone = true;
		}
		this->sprite.setTextureRect(this->currentRect);
	}
}

/*
void Animation::play(const float& dt, const float& modifier, const float& modifier_max)//TEST
{
	this->animationSequenceDone = false;
	//Update time
	float percentage = (modifier / modifier_max);
	if (percentage < 0.5f) {
		percentage = 0.5f;
	}
	this->timer += percentage * 100.f * dt;
	if (this->timer >= this->animationTimer) {
		//reset timer
		this->timer = 0.f;

		if (this->currentRect != this->endRec) {
			this->currentRect.left += this->width;
		}
		else {
			this->currentRect.left = this->startRec.left;
			this->animationSequenceDone = true;
		}
		this->sprite.setTextureRect(this->currentRect);
	}
}
*/

void Animation::pause()
{
}

void Animation::reset()
{
	this->timer = this->animationTimer;
	this->currentRect = this->startRec;
}
