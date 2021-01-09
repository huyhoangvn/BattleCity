#include "Game.h"

//Private Function
void Game::initializeVariable()
{
	this->window = nullptr;
	this->fullscreen = false;
	this->dt = 0.f;
}

void Game::initWindow()
{
	/*
	// Create a SFML window using option  from a  window.ini file
	*/
	this->videoMode = sf::VideoMode::getFullscreenModes();
	//init variable for ifstream 
	std::string title = "None";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	unsigned framerate_limit = 60; 
	bool verticle_sync_enable = 0;
	unsigned antialiasing_lever = 0;
	//read file stream
	std::ifstream ifs("config/window.ini");
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> this->fullscreen;
		ifs >> framerate_limit;
		ifs >> verticle_sync_enable;
		ifs >> antialiasing_lever;
	}
	ifs.close();
	//init 
	this->windowSetting.antialiasingLevel = antialiasing_lever;
	if (this->fullscreen) {
		this->window = new sf::RenderWindow(window_bounds, title, 
			sf::Style::Fullscreen, this->windowSetting);
	}
	else {
		this->window = new sf::RenderWindow(window_bounds, title,
			sf::Style::Titlebar | sf::Style::Close, this->windowSetting);
	}
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(verticle_sync_enable);
}

void Game::initKey()
{
	std::ifstream ifs("config/supported_keys.ini");

	if (ifs.is_open()) {
		std::string key = "";
		int value = 0;
		while (ifs >> key >> value) {
			this->supportedKeys[key] = value;
		}
	}

	ifs.close();
}


void Game::initStates()
{
	this->states.push(
		new MainMenu(this->window, &this->supportedKeys, &this->states));
}

//Constructor
Game::Game()
{
	this->initializeVariable();
	this->initWindow();
	this->initKey();
	this->initStates();
}

//Destructor
Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();//remove data
		this->states.pop();//remove ptr
	}
}

//Accessor
void Game::run()
{
	while (this->window->isOpen()) {

		//Update
		this->updateDt();
		this->update();

		//Render
		this->render();
	}
}

void Game::endApplication()
{
	std::cout << "End App\n";
}

void Game::updateDt()
{
	/* 
	// Update the delta time variable with the time it take 
	// to update and render one frame 
	*/

	this->dt = this->dtClock.restart().asSeconds();

	system("cls");

}

//Fuction
void Game::updateEvent()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape) {
					this->window->close();
				}
				break;
		}
	}
}

void Game::update()
{
	this->updateEvent();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();//prepare to end the state
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		//End application
		this->endApplication();//replace for destructor
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear(sf::Color::White);

	//Draw game object
	if (!this->states.empty()) {
		this->states.top()->render();//default render window
	}

	this->window->display();
}
