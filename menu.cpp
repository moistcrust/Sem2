#include "menu.h"

void menu::update() {
    game::update();
}

void menu::render() {
    game::render();
    window.clear(sf::Color::Black);
    window.draw(button1.shape);
    window.draw(button1.text);
    window.draw(button2.shape);
    window.draw(button2.text);
    window.draw(button3.shape);
    window.draw(button3.text);

    window.display();
}

void menu::eventhandle() {
    game::eventhandle();
}

menu::menu() {
    font.loadFromFile("pricedown bl.otf");
    button1 = Button(300, 200, 200, 50, font, "Game 1");
    button2 = Button(300, 300, 200, 50, font, "Game 2");
    button3 = Button(300, 400, 200, 50, font, "Game 3");
}

void menu::init() {
    videomode.height = 1200;
    videomode.width = 1200;
    settings.antialiasingLevel = 8;
    window.create(videomode,"New Game",sf::Style::Titlebar | sf::Style::Close,settings);
}


