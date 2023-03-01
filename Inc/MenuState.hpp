#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GameState.hpp"


class MenuState : public GameState {

public:
    MenuState(Game* game);

    void draw(const float dt);
    void update(const float dt);
    void handleInput();

private:
    sf::View view;
//    std::vector<sf::RectangleShape*>shapes;
//    std::vector<sf::Text*> textes;

    std::vector<sf::Sprite*> sprites;
    std::vector<sf::Texture*>textures;

    void loadgame();

};

#endif /* GAME_STATE_START_HPP */
