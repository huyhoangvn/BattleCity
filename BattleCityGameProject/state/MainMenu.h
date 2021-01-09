#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "State.h"
#include "../resources/button/Button.h"

class MainMenu : public State
{
private:

protected:
	//Context
	sf::Text introTitle;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;
	//Supporter
	std::map<std::string, Button*> button;
	//Function
	void initVariable();
	void initFont();
	void initButton();
	void initIntroTitle();
	void initKeybinds();
	void initBackground();
public:
	MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*> *states);
	virtual ~MainMenu();

	//Function 
	virtual void updateInput(const float& dt);

	//update
	void updateButton(const sf::Vector2f mousePosition);
	void update(const float& dt);

	//render
	void renderButton(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};

#endif
