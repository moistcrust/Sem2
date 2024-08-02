#include "game.h"

void game::eventhandle(sf::RenderWindow &window) {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void game::update(sf::RenderWindow &window) {
}

void game::render(sf::RenderWindow &window) {
}

game::game(const sf::RenderWindow &window) {
    const sf::Vector2u size = window.getSize();
    center[0] = size.x/2;
    center[1] = size.y/2;
}
game::~game() = default;


