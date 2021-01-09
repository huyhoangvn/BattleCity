#include "MainMenu.h"
#include "GameState.h"


void MainMenu::initVariable()
{
}

void MainMenu::initFont()
{
	if (!this->font.loadFromFile("resources/fonts/ARCADECLASSIC.TTF")) {
		throw("ERROR::STATE::MAIN_MENU::COULD NOT LOAD FONT");
	}
}

void MainMenu::initButton()
{
	//INPUT FROM FILE CONFIG IN THE FUTURE

	//Button Position:	x , y
	//Button Size:		width , height
	//Text:				font , text string , character size , text color
	//Button Click:     idle , hover , active
	this->button["GAME_STATE"] = new Button(
		this->window->getSize().x / 2.f - 75, this->window->getSize().y / 2.35f,
		150, 60,
		&this->font, "PLAY", 30, sf::Color::Black,
		sf::Color(144, 175, 243, 150), sf::Color(144, 141, 243, 150), sf::Color(20, 75, 193, 150));

	this->button["SETTING_STATE"] = new Button(
		this->window->getSize().x / 2.f - 75, this->window->getSize().y / 1.8f,
		150, 60,
		&this->font, "SETTING", 30, sf::Color::Black,
		sf::Color(144, 175, 243, 150), sf::Color(144, 141, 243, 150), sf::Color(20, 75, 193, 150));

	this->button["HELP_STATE"] = new Button(
		this->window->getSize().x / 2.f - 75, this->window->getSize().y / 1.45f,
		150, 60,
		&this->font, "HELP", 30, sf::Color::Black,
		sf::Color(144, 175, 243, 150), sf::Color(144, 141, 243, 150), sf::Color(20, 75, 193, 150));

	this->button["EXIT_STATE"] = new Button(
		this->window->getSize().x / 2.f - 75, this->window->getSize().y / 1.2f,
		150, 60,
		&this->font, "QUIT", 30, sf::Color::Black,
		sf::Color(144, 175, 243, 150), sf::Color(144, 141, 243, 150), sf::Color(20, 75, 193, 150));
}

void MainMenu::initKeybinds()
{
	this->getKeybindsConfig("config/mainmenu_keys.ini");
}

void MainMenu::initBackground()
{

	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);
	
	if (!this->backgroundTexture.loadFromFile("resources/images/backgrounds/mainmenu_background.png")) {
		throw("ERROR::STATE::MAINMENU:: COULD NOT LOAD BACK GROUND IMAGE");
	}
	this->backgroundTexture.setSmooth(true);
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenu::initIntroTitle() {
	this->introTitle.setString("BATTLE CITY");
	this->introTitle.setFillColor(sf::Color::Black);
	this->introTitle.setFont(this->font);
	this->introTitle.setCharacterSize(100);
	this->introTitle.setPosition(sf::Vector2f(
		this->window->getSize().x / 2.f - this->introTitle.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 4.f - this->introTitle.getGlobalBounds().height / 1.5f
	));
}

MainMenu::MainMenu(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*> *states)
	:State(window, supportedKeys, states)
{
	this->initVariable();
	this->initFont();
	this->initButton();
	this->initIntroTitle();
	this->initKeybinds();
	this->initBackground();
}

MainMenu::~MainMenu()
{
	auto itr = this->button.begin();
	for (itr = this->button.begin(); itr != this->button.end(); ++itr) {
		delete itr->second;
	}
}

void MainMenu::updateInput(const float& dt)
{

}

void MainMenu::updateButton(const sf::Vector2f mousePosition)
{
	for (auto& itr : this->button) {
		itr.second->update(mousePosition);
	}
	//Input Handle
	if (this->button.at("EXIT_STATE")->isPressed()) {
		this->endState();
	}
	if (this->button.at("GAME_STATE")->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}
}

void MainMenu::update(const float& dt)
{
	this->updateMousePosition();
	this->updateInput(dt);
	this->updateButton(this->mousePosView);
}

void MainMenu::renderButton(sf::RenderTarget& target)
{
	for (auto& itr : this->button) {
		itr.second->render(target);
	}
}

void MainMenu::render(sf::RenderTarget* target)
{
	if (!target) {
		target = this->window;
	}
	//if dont have target then render window
	target->draw(this->background);
	target->draw(this->introTitle);
	this->renderButton(*target);
}
