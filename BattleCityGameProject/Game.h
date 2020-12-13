#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

/*
	Class act as the game engine
	Wrapper class.
*/

class Game
{
private:
	//Variable 
	//Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	//Game Object

	//Private function 
	void initializeVariable();
	void initWindow();
public:
	//Constructor / Destructor
	Game();
	virtual ~Game();

	//Accessor
	const bool runing() const;

	//Fuction
	void updateEvent();
	void update();
	void render();
};

#endif

