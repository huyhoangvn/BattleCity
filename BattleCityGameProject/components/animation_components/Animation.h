#ifndef ANIMATION_H
#define ANIMATION_H

#include "../../header/Dependences.h"

class Animation {
protected:
	sf::Sprite &sprite;
	sf::Texture &textureSheet;
	float animationTimer;
	float timer;
	float speed;
	int width;
	int height;
	sf::IntRect startRec;
	sf::IntRect currentRect;
	sf::IntRect endRec;
	
	bool animationSequenceDone;
	//function
	void initVariable();

public:
	Animation(sf::Sprite &sprite, sf::Texture& textureSheet,
		float animationTimer, 
		int xStartFrame, int yStartFrame, int xFrame, int yFrame,
		int width, int height);
	virtual ~Animation();
	
	//Function
	const bool& isFinishedAnimationSequence();
	void play(const float& dt);
	//void play(const float& dt, const float& modifier, const float& modifier_max);//TEST
	void pause();
	void reset();
};

#endif 