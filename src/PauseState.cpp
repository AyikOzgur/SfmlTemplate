/*
 * PauseState.cpp
 *
 *  Created on: Mar 1, 2023
 *      Author: ozgur
 */



#include "SFML/Graphics.hpp"

#include <iostream>
#include "PauseState.hpp"
#include "GameState.hpp"
#include "game.hpp"

PauseState::PauseState(Game *game)
{
	this->game=game;
	sf::Vector2u size_window = game->window.getSize();
	for (int i=0 ; i<1;i++){
	textures.push_back(new sf::Texture);
	sprites.push_back(new sf::Sprite);
	}
    textures.at(0)->loadFromFile("./Img/paused.png");


    for(int i=0; i<1; i++){
    sprites.at(i)->setTexture(*textures.at(i));
    sprites.at(i)->setOrigin(textures.at(i)->getSize().x/2,textures.at(i)->getSize().y/2);

    }

    sprites.at(0)->setPosition(size_window.x/2,150);
    sprites[0]->setScale(sf::Vector2f(0.25,0.25));

}



void PauseState::handleInput()
{
    sf::Event event;

    while (game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
        case sf::Event::Closed:
            game->window.close();
            break;

            /* Change Between game states */
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                playGame();
            break;


        }
    }

}

void PauseState::update(float dt){


}

void PauseState::draw(float dt)
{
	game->window.draw(*sprites[0]);
}

void PauseState::playGame()
{
	game->pushState(game_states::Playing);
}
