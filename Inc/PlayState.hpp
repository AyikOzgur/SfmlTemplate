/*
 * PlayState.hpp
 *
 *  Created on: Feb 28, 2023
 *      Author: ozgur
 */

#ifndef PLAYSTATE_HPP_
#define PLAYSTATE_HPP_

#include "GameState.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"

class PlayState : public GameState
{
public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    PlayState(Game *game);

private:
    void PauseGame();
    sf::Vector2f increment;
    sf::Texture mushroom_texture;
    sf::Sprite mushroom;
    sf::Vector2u size;
};

#endif /* PLAYSTATE_HPP_ */
