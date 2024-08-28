/*
 * game.cpp
 *
 *  Created on: Feb 27, 2023
 *      Author: ozgur
 */

#include <game.hpp>
#include "SFML/Graphics.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "PauseState.hpp"

Game::Game()
{
    // pushState(new PlayState(this));
    // pushState(new MenuState(this));  //we want to create a pointer at the game objects address. this will enter our menu.
    window.create(sf::VideoMode(800, 600), "SFML TEMPLATE");
    window.setFramerateLimit(60);
    states.push_back(new MenuState(this));
    states.push_back(new PlayState(this));
    states.push_back(new PauseState(this));
}

Game::~Game()
{
    while (!states.empty())
        popState();
}

void Game::pushState(game_states state)
{
    state_index = state;
}

void Game::popState()
{
    states.back();
    delete states.back();
    states.pop_back();
}

GameState *Game::CurrentState()
{
    if (states.empty())
        return nullptr;
    else
        return states.at(state_index);
    // return states.back();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        // control frame rate (you can ignore this stuff for now)
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        // exception handling
        if (CurrentState() == nullptr)
            continue;

        // get user input for current game state
        CurrentState()->handleInput();

        // update anything neccessary
        CurrentState()->update(dt);

        // clear window
        window.clear();

        // draw anything in the current game state
        CurrentState()->draw(dt);

        window.display();
    }
}
