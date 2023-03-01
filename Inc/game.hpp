#ifndef GAME_HPP
#define GAME_HPP


#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class GameState;
enum game_states{Menu=0,Playing,Pause};


class Game
{
public:
    //constructor and deconstructor
    Game();
    ~Game();

    //functions for changing game state
    void pushState(game_states state);
    void popState();

    //function to get the current State (note this function must be a pointer)
    GameState* CurrentState();

    //game loop function
    void gameLoop();

    //sfml window
    sf::RenderWindow window;

private:
    std::vector<GameState*> states;
    game_states state_index=Menu;

};

#endif /* GAME_HPP */
