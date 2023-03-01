/*
 * PauseState.hpp
 *
 *  Created on: Mar 1, 2023
 *      Author: ozgur
 */

#ifndef PAUSESTATE_HPP_
#define PAUSESTATE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameState.hpp"

class PauseState : public GameState {

public:
    PauseState(Game* game);

    void draw(const float dt);
    void update(const float dt);
    void handleInput();

private:
    std::vector<sf::Sprite*> sprites;
    std::vector<sf::Texture*>textures;
    void playGame();

};



#endif /* PAUSESTATE_HPP_ */
