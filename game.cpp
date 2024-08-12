#include "game.h"

void Game::eventhandle() {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.display();
}

int Game::getchangestate() {
    return 0;
}


Game::Game(sf::RenderWindow& window) : window(window) {
}


Game::~Game() = default;