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
    sf::RenderWindow& window;
    virtual void eventhandle();
    virtual void update();
    virtual void render();
    virtual int getchangestate();
    explicit Game(sf::RenderWindow&);
    virtual ~Game();
};

#endif