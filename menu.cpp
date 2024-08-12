#include "menu.h"

void menu::update() {
    if (isMute) {
        music.setVolume(0);
    }
    else {
        music.setVolume(100);
    }
    if (isMousereleased) {
        int i = 1;
        isMousepressed = false;
        for (auto& button : buttons) {
            if (button.isClicked(click_pos_x, click_pos_y) and button.isClicked(mouse_pos[0], mouse_pos[1])) {
                changestate = i;
            }
            i++;
        }
        isMousereleased = false;
    }
    if (isMousepressed) {
        for (auto& button : buttons) {
            if (button.isClicked(mouse_pos[0], mouse_pos[1])) {
                if (not button.isMoved) {
                    button.setScale(1.1, 1.1);
                    button.text.setScale(1.1, 1.1);
                    button.isMoved = true;
                }
            }
            else {
                if (button.isMoved) {
                    button.isMoved = false;
                    button.setScale(1, 1);
                    button.text.setScale(1, 1);
                }
            }
        }
    }
    else {
        for (auto& button : buttons) {
            if (button.isMoved) {
                button.isMoved = false;
                button.setScale(1, 1);
                button.text.setScale(1, 1);
            }
        }
    }
    if (menuClock.getElapsedTime().asMilliseconds() >= 5) {
        for (auto& button : buttons) {
            button.animate();
        }
        animate_background();
    }
    
}


void menu::render() {
    if (menuClock.getElapsedTime().asMilliseconds() >= 5) {
        menuClock.restart();
        window.clear(sf::Color::Black);
        window.draw(background_sprite);
        window.draw(music_button.sprite);
        for (auto& button : buttons) {
            window.draw(button.sprite);
            window.draw(button.text);
        }
        window.display();
    }
}

void menu::eventhandle() {
    while (window.pollEvent(ev)) {
        mouse_pos[0] = sf::Mouse::getPosition(window).x;
        mouse_pos[1] = sf::Mouse::getPosition(window).y;
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
        if (ev.type == sf::Event::MouseButtonPressed) {
            if (ev.mouseButton.button == sf::Mouse::Left) {
                if (not isMousepressed) {
                    click_pos_x = mouse_pos[0];
                    click_pos_y = mouse_pos[1];
                }
                isMousepressed = true;
            }
        }
        if (ev.type == sf::Event::MouseButtonReleased) {
            if (ev.mouseButton.button == sf::Mouse::Left) {
                isMousereleased = true;
                if (music_button.isClicked(click_pos_x, click_pos_x) and music_button.isClicked(mouse_pos[0], mouse_pos[1])) {
                    isMute = (not isMute);
                }
            }
        }
    }
}

int menu::getchangestate() {
    return changestate;
}

void menu::animate_background() {
    // Define the movement boundaries
    int max_x = background_texture.getSize().x * 0.4 - window.getSize().x;
    int max_y = background_texture.getSize().y * 0.4 - window.getSize().y;

    if (-bg_pos[0] < max_x && int(bg_pos[1]) == 0) {
        bg_pos[0] -= 0.5; // Move right
    }
    else if (int(-bg_pos[0]) == max_x && -bg_pos[1] < max_y) {
        bg_pos[1] -= 0.5; // Move down
    }
    else if (-bg_pos[0] > 0 && int(-bg_pos[1]) == max_y) {
        bg_pos[0] += 0.5; // Move left
    }
    else if (int(-bg_pos[0]) == 0 && -bg_pos[1] > 0) {
        bg_pos[1] += 0.5; // Move up
    }
    background_sprite.setPosition(bg_pos[0], bg_pos[1]);
}




menu::menu(sf::RenderWindow& window) : Game(window) {
    changestate = 0;
    mouse_pos[0] = 0;
    mouse_pos[1] = 0;
    background_texture.loadFromFile("../resources/background.png");
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(bg_pos[0], bg_pos[1]);
    background_sprite.setScale(.4, .4);

    font.loadFromFile("../resources/KnightWarrior-w16n8.otf");
    button_texture.loadFromFile("../resources/button.png");
    button.setTexture(button_texture);

    music_texture.loadFromFile("../resources/speaker.png");
    music_button.setTexture(music_texture);
    music_button.setPosition(0, 0);
    music_button.setScale(50 / music_button.sprite.getLocalBounds().width, 50 / music_button.sprite.getLocalBounds().height);

    for (int i = 0; i < 4; i++) {
        buttons.emplace_back(button_texture, 600, 200 + 120 * i);
        buttons[i].spritescale[0] = 200 / button.sprite.getLocalBounds().width;
        buttons[i].spritescale[1] = 60 / button.sprite.getLocalBounds().height;
        buttons[i].setText("Game", font);
        buttons[i].setScale(1, 1);
    }
    isMousepressed = false;
    isMousereleased = false;
    music.openFromFile("../resources/sound.ogg");
    isMute = false;
    music.setLoop(true);
    music.play();
}

menu::~menu() {
    music.stop();
};
