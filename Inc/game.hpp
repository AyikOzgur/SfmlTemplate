#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class GameState;
enum game_states
{
    Menu = 0,
    Playing,
    Pause
};

class Game
{
public:
    Game();
    ~Game();

    void pushState(game_states state);
    void popState();

    GameState *CurrentState();

    void gameLoop();

    sf::RenderWindow window;

private:
    std::vector<GameState *> states;
    game_states state_index = Menu;
};

#endif /* GAME_HPP */
