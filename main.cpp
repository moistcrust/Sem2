#include "menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200,800),"New Game",sf::Style::Titlebar | sf::Style::Close);
    menu Game(window);
    while (window.isOpen()) {
        Game.eventhandle(window);
        Game.render(window);
    }
    return 0;
}
