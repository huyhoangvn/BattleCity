#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include "../../header/Dependences.h"
#include "Animation.h"

class AnimationComponent
{
private:

protected:
	std::map<std::string, Animation*> animationsMap;
	sf::Sprite& sprite;
	sf::Texture& textureSheet;

	Animation* lastAnimation;
	bool animationSequenceDone;
	//Animation* priorityAnimation;

	//Init Function
	void initVariable();
public:
	AnimationComponent(sf::Sprite &sprite, sf::Texture &textureSheet);
	virtual ~AnimationComponent();

	void addAnimation(const std::string key,
		float animationTimer,
		int xStartFrame, int yStartFrame, int xFrame, int yFrame,
		int width, int height);

	//function
	const bool& isFinishedAnimationSequence();

	void play(const std::string key, const float &dt);
	//void play(const std::string key, const float& dt, const float& modifier, const float& modifier_max, const bool priority = false);//TEST
};

#endif 