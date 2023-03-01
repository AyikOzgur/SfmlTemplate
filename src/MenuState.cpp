/*
 * MenuState.cpp
 *
 *  Created on: Feb 27, 2023
 *      Author: ozgur
 */
#include "SFML/Graphics.hpp"

#include <iostream>
#include "MenuState.hpp"
#include "GameState.hpp"
#include "game.hpp"


MenuState::MenuState(Game* game)
{
	this->game = game;
	sf::Vector2u size_window = game->window.getSize();
	sf::Vector2f size_rec;

		for (int i=0 ; i<3;i++){
		textures.push_back(new sf::Texture);
		sprites.push_back(new sf::Sprite);
		}
	    textures.at(0)->loadFromFile("./Img/play.png");
	    textures.at(1)->loadFromFile("./Img/settings.png");
	    textures.at(2)->loadFromFile("./Img/exit.png");

	    for(int i=0; i<3; i++){
	    sprites.at(i)->setTexture(*textures.at(i));
	    sprites.at(i)->setOrigin(textures.at(i)->getSize().x/2,textures.at(i)->getSize().y/2);

	    }

	    sprites.at(0)->setPosition(size_window.x/2,150);
	    sprites[0]->setScale(sf::Vector2f(0.25,0.25));


	    sprites.at(1)->setPosition(size_window.x/2,340);
	    sprites[1]->setScale(0.4,0.4);


	    sprites.at(2)->setPosition(size_window.x/2,500);
	    sprites[2]->setScale(0.35,0.35);


}

//MenuState::~MenuState(){}

void MenuState::handleInput()
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
                game->window.close();
            else if (event.key.code == sf::Keyboard::Space)
                loadgame();
       break;

        case sf::Event::MouseButtonPressed:

			if(sprites.at(0)->getGlobalBounds().contains(game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window))))
			{
				// mouse is on sprite 0 which is play button!
				loadgame();
			}
			else if (sprites.at(1)->getGlobalBounds().contains(game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window))))
			{
               //load settings, it doesnt exist yet!!

			}
			else if (sprites.at(2)->getGlobalBounds().contains(game->window.mapPixelToCoords(sf::Mouse::getPosition(game->window))))
			{
				// mouse is on sprite 2 which is exit button
                game->window.close();

			}
		break;


        }
    }

}

void MenuState::update(const float dt)
{
	//state_index=Menu;

}

void MenuState::draw(const float dt)
{

//    sf::RectangleShape rect;
//    rect.setPosition(sf::Vector2f(100, 100));
//    rect.setSize(sf::Vector2f(100, 100));
//    rect.setFillColor(sf::Color::Red);
//
//    game->window.draw(rect);

	for(int i =0; i<4;i++){
    	//    game->window.draw(*shapes[i]);
	}
	game->window.draw(*sprites.at(0));
	game->window.draw(*sprites.at(1));
	game->window.draw(*sprites.at(2));


}

void MenuState::loadgame()
{

  //make this load the play game game state.
    game->pushState(game_states::Playing);


}

