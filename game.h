#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class game {
public:
    sf::Event ev{};
    int center[2];
    virtual void eventhandle(sf::RenderWindow &window);
    virtual void update(sf::RenderWindow &window);
    virtual void render(sf::RenderWindow &window);

    game(const sf::RenderWindow &window);
    virtual ~game();
};

#endif