#include "game.h"

void Game::eventhandle(sf::RenderWindow &window) {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update(sf::RenderWindow &window) {
}

void Game::render(sf::RenderWindow &window) {
}
Game::~Game() = default;


