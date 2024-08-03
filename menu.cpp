//
// Created by NITRO on 8/2/2024.
//

#include "menu.h"

void menu::update() {
}

void menu::render(sf::RenderWindow &window) {
    Game::render(window);
    window.clear(sf::Color::Black);
    animate_background();
    window.draw(background_sprite);
    for (auto& button : buttons) {
        button.animate();
        window.draw(button.sprite);
    }
    window.display();
}

void menu::eventhandle(sf::RenderWindow &window) {
    Game::eventhandle(window);
}
#include <iostream>
void menu::animate_background() {
    // Define the movement boundaries
    int max_x = background_texture.getSize().x * 0.4 - 1200;
    int max_y = background_texture.getSize().y * 0.4 - 800;

    // Debugging output
    std::cout << "bg_pos[0]: " << bg_pos[0] << ", bg_pos[1]: " << bg_pos[1] << std::endl;

    if (-bg_pos[0] < max_x && bg_pos[1] == 0) {
        bg_pos[0] -= 0.1; // Move right
    } else if (-bg_pos[0] >= max_x && -bg_pos[1] < max_y) {
        bg_pos[1] -= 0.1; // Move down
    } else if (-bg_pos[0] > 0 && -bg_pos[1] >= max_y) {
        bg_pos[0] += 0.1; // Move left
    } else if (bg_pos[0] >= 0 && -bg_pos[1] > 0) {
        bg_pos[1] += 0.1; // Move up
    }

    background_sprite.setPosition(bg_pos[0], bg_pos[1]);
}




menu::menu() {
    background_texture.loadFromFile("background.png");
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(bg_pos[0],bg_pos[1]);
    background_sprite.setScale(.4,.4);


    button_texture.loadFromFile("button.png");
    button.setTexture(button_texture);

    for (int i = 0;i<3;i++) {
        buttons.emplace_back(button_texture, 500, 200+80*i,200/button.sprite.getLocalBounds().width,60/button.sprite.getLocalBounds().height);
    }
}

menu::~menu() = default;
