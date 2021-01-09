#ifndef DEPENDENCE_H
#define DEPENDENCE_H

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

enum class ActionState {
	UNKNOWN = 0,
	IDLE,
	MOVE,
	ATK
};

enum class DirectionState {
	UNKNOWN = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum ButtonState {
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_PRESS,
};

enum class HpbarPlacement {
	ABOVE,
	BENEATH,
	LEFT,
	RIGHT
};

#endif 