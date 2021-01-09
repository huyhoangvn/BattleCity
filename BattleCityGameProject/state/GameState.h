#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"

class GameState : public State
{
private:

protected:
	Player* player1;
	Player* player2;

	//function
	void initKeybinds();
	void initTexture();
	void initPlayer();
public:
	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*> *states);
	virtual ~GameState();

	//Function 
	virtual void updateInput(const float& dt);
	virtual void updatePlayerInput();
	void update(const float& dt);
	void render(sf::RenderTarget* target);
};

#endif
