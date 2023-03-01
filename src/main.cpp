//============================================================================
// Name        : Snake_V1.cpp
// Author      : ozgur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

using namespace std;

int main() {

    Game game; //create game object (so far this constructor just intiializes our window)

    game.gameLoop();

    return 0;
}
