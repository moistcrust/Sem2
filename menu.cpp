#include "menu.h"

void menu::update(sf::RenderWindow &window) {
}

void menu::render(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);
    window.draw(button1.shape);
    window.draw(button1.text);
    window.draw(button2.shape);
    window.draw(button2.text);
    window.draw(button3.shape);
    window.draw(button3.text);
    window.display();
}

void menu::eventhandle(sf::RenderWindow &window) {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
    }
}

menu::menu(const sf::RenderWindow &window): game(window) {
    font.loadFromFile("KnightWarrior-w16n8.otf");
    button1 = Button(center[0] - 100, 200, 200, 50, font, "Game 1");
    button2 = Button(center[0] - 100, 300, 200, 50, font, "Game 2");
    button3 = Button(center[0] - 100, 400, 200, 50, font, "Game 3");
}
