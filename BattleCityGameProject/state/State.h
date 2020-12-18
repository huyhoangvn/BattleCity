#ifndef STATE_H
#define STATE_H

#include "../entities/Entity.h"

class State
{
private:

protected:
	sf::RenderWindow *window;//context
	std::map<std::string, int> *supportedKeys;
	std::map<std::string, int> keybinds;
	std::vector<sf::Texture> texture;
	bool quit;

	//Function
	virtual void initKeybinds() = 0;

public:
	State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
	virtual ~State();

	//Need to define 
	virtual void checkForQuit();
	const bool& getQuit() const;

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif

