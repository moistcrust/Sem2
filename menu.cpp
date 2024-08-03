//
// Created by NITRO on 8/2/2024.
//

#include "menu.h"

void menu::update() {
    Game::update();
}

void menu::render(sf::RenderWindow &window) {
    Game::render(window);
    window.clear(sf::Color::Black);
    for (auto& button : buttons) {
        button.animate();
        window.draw(button.sprite);
    }
    window.display();
}

void menu::eventhandle(sf::RenderWindow &window) {
    Game::eventhandle(window);
}

menu::menu() {
    texture.loadFromFile("button.png");
    button.setTexture(texture);

    for (int i = 0;i<3;i++) {
        buttons.emplace_back(texture, 500, 200+80*i,200/button.sprite.getLocalBounds().width,60/button.sprite.getLocalBounds().height);
    }
}

menu::~menu() = default;
