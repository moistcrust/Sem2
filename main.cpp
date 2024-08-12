#include "StateManager.h"
#include "menu.h"
#include "missile.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "New Game", sf::Style::Titlebar | sf::Style::Close);
    StateManager stateManager(window);

    stateManager.pushState(std::make_unique<menu>(window));

    sf::Clock clock;
    while (window.isOpen()) {
        stateManager.handleEvents();
        stateManager.update();
        stateManager.render();
        if (!stateManager.states.empty() && stateManager.states.top()->getchangestate() !=0) {
            int change = stateManager.states.top()->getchangestate();
            if (change == 1) {
                stateManager.changeState(std::make_unique<missile>(window));
            }
            else if (change == -1) {
                stateManager.changeState(std::make_unique<menu>(window));
            }
        }
    }

    return 0;
}
