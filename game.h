#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class game {
    virtual void init();
public:
    sf::VideoMode videomode;
    sf::RenderWindow window{};
    sf::Event ev{};
    sf::ContextSettings settings;
    virtual void eventhandle();
    virtual void update();
    virtual void render();
    game();
    virtual ~game();
};

#endif