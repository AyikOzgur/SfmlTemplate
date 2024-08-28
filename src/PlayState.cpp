/*
 * PlayState.cpp
 *
 *  Created on: Feb 28, 2023
 *      Author: ozgur
 */

#include "PlayState.hpp"
#include "MenuState.hpp"
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

void PlayState::draw(const float dt)
{

    game->window.draw(mushroom);
}

void PlayState::update(const float dt)
{
    if ((mushroom.getPosition().x + (size.x / 2) > game->window.getSize().x && increment.x > 0) || (mushroom.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
    {
        increment.x = -increment.x; // reverse direction in x
    }

    if ((mushroom.getPosition().y + (size.y / 2) > game->window.getSize().y && increment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
    {
        increment.y = -increment.y; // reverse direction in y
    }

    mushroom.setPosition(mushroom.getPosition() + increment);
}

void PlayState::handleInput()
{
    sf::Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
        case sf::Event::Closed:
            this->game->window.close();
            break;

            // pause game
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                PauseGame();
            break;
        }
    }
}

PlayState::PlayState(Game *game)
{

    this->game = game;
    increment = sf::Vector2f(1.0f, 1.0f);
    mushroom_texture.loadFromFile("./Img/mashroom.png");
    size = mushroom_texture.getSize();
    mushroom.setTexture(mushroom_texture);
    mushroom.setOrigin(mushroom_texture.getSize().x / 2, mushroom_texture.getSize().y / 2);
}

void PlayState::PauseGame()
{
    game->pushState(game_states::Pause);
}
