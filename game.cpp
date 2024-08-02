#include "game.h"

void game::init() {
    videomode.height = 800;
    videomode.width = 1200;
    window.create(videomode,"New Game",sf::Style::Titlebar | sf::Style::Close);
}

void game::eventhandle() {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void game::update() {
}

void game::render() {
}

game::game() {
    game::init();
}
game::~game() = default;


