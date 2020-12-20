#ifndef GAME_H
#define GAME_H

#include "../state/State.h"
#include "../state/MainMenu.h"

/*
	Class act as the game engine
	Wrapper class.
*/

class Game
{
private:

protected:
	//Variable 
	//Window
	sf::RenderWindow* window;
	sf::Event event;
	std::vector<sf::VideoMode> videoMode;
	sf::ContextSettings windowSetting;
	bool fullscreen;
	//Render 
	sf::Clock dtClock;
	float dt;//delta time for frame rate 
	//State
	std::stack<State*> states;
	//Keybind map
	std::map<std::string, int> supportedKeys;
	//Private function 
	void initializeVariable();
	void initWindow();
	void initKey();
	void initStates();
public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessor
	void run();

	//Regular
	void endApplication();

	//Fuction
	void updateDt();
	void updateEvent();
	void update();

	//Render
	void render();
};

#endif

