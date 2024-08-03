//
// Created by NITRO on 8/2/2024.
//

#include "menu.h"

void menu::update(sf::RenderWindow &window) {
    if (isMute) {
        music.setVolume(0);
    }
    else {
        music.setVolume(100);
    }
    window.clear(sf::Color::Black);
    animate_background();
    for (auto& button: buttons) {
        if(isMousedpressed) {
          if (button.isClicked(mouse_pos[0],mouse_pos[1])) {
              continue;
          }
        };
        button.animate();
    }
}

void menu::render(sf::RenderWindow &window) {
    Game::render(window);
    window.draw(background_sprite);
    window.draw(music_button.sprite);
    for (auto& button : buttons) {
        window.draw(button.sprite);
        window.draw(button.text);
    }
    window.display();
}

void menu::eventhandle(sf::RenderWindow &window) {
    while (window.pollEvent(ev)) {
        mouse_pos[0] = sf::Mouse::getPosition(window).x;
        mouse_pos[1] = sf::Mouse::getPosition(window).y;
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
        if (ev.type == sf::Event::MouseButtonPressed) {
            if (ev.mouseButton.button == sf::Mouse::Left) {
                isMousedpressed = true;
                if (music_button.isClicked(mouse_pos[0],mouse_pos[1])) {
                    isMute = (not isMute);
                }
            }
        }
        if (ev.type == sf::Event::MouseButtonReleased) {
            if (ev.mouseButton.button == sf::Mouse::Left) {
                isMousedpressed = false;
            }
        }
    }
}

void menu::animate_background() {
    // Define the movement boundaries
    int max_x = background_texture.getSize().x * 0.4 - 1200;
    int max_y = background_texture.getSize().y * 0.4 - 800;

    if (-bg_pos[0] < max_x && int(bg_pos[1]) == 0) {
        bg_pos[0] -= 0.1; // Move right
    } else if (int(-bg_pos[0]) == max_x && -bg_pos[1] < max_y) {
        bg_pos[1] -= 0.1; // Move down
    } else if (-bg_pos[0] > 0 && int(-bg_pos[1]) == max_y) {
        bg_pos[0] += 0.1; // Move left
    } else if (int(-bg_pos[0]) == 0 && -bg_pos[1] > 0) {
        bg_pos[1] += 0.1; // Move up
    }

    background_sprite.setPosition(bg_pos[0], bg_pos[1]);
}




menu::menu() {
    background_texture.loadFromFile("background.png");
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(bg_pos[0], bg_pos[1]);
    background_sprite.setScale(.4, .4);

    font.loadFromFile("KnightWarrior-w16n8.otf");

    music_texture.loadFromFile("speaker.png");
    music_button.setTexture(music_texture);
    music_button.setPosition(0,0);
    music_button.setScale(50/music_button.sprite.getLocalBounds().width,50/music_button.sprite.getLocalBounds().height);

    button_texture.loadFromFile("button.png");
    button.setTexture(button_texture);

    for (int i = 0; i < 4; i++) {
        buttons.emplace_back(button_texture, 500, 200 + 80 * i, 200 / button.sprite.getLocalBounds().width,
                             60 / button.sprite.getLocalBounds().height);
        buttons[i].setText("Game", font);
    }
    isMute = false;
    isMousedpressed = false;
    music.openFromFile("audio.ogg");
    music.setLoop(true);
    music.play();
}

menu::~menu() {
    music.stop();
};
