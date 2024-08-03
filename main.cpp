#include "game.h"
#include "menu.h"
#include "button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200,800),"New Game",sf::Style::Titlebar | sf::Style::Close);
    menu game;
    while (window.isOpen()) {
        game.eventhandle(window);
        game.update(window);
        game.render(window);
    }
    return 0;
}
