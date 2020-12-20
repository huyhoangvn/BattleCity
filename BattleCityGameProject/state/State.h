#ifndef STATE_H
#define STATE_H

#include "../entities/Player.h"

class State
{
private:

protected:
	//States Ptr
	std::stack<State*> *states;
	//Context
	sf::RenderWindow *window;
	std::map<std::string, sf::Texture> texture;
	
	//Key
	std::map<std::string, int> *supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	//Mouse
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Function
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State*> *states);
	virtual ~State();

	//Function
	//End state
	const bool& getQuit() const;
	virtual void endState();
	//Key Handle
	virtual void getKeybindsConfig(std::string iniFileName);
	virtual void updateInput(const float& dt) = 0;
	//Mouse Handle
	virtual void updateMousePosition();
	//Run
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif

