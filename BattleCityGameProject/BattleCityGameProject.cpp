#include <iostream>
#include "Game.h"

int main() {
	//Init game engine
	Game game;
	//Game loop
	while (game.runing()) {

		//Update
		game.update();

		//Render
		game.render();
	}
	return 0;
}