#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Game {
public:
    sf::Event ev{};
    virtual void eventhandle(sf::RenderWindow &window);
    virtual void update(sf::RenderWindow &window);
    virtual void render(sf::RenderWindow &window);
    virtual ~Game();
};

#endif