#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State
{
private:

protected:
	Entity player;

	//function
	void initKeybinds();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	//Function 
	virtual void updateInput(const float& dt);
	virtual void updatePlayerInput(const float& dt);
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif
