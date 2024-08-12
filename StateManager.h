#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include "game.h"
#include <memory>
#include <stack>

class StateManager {
public:
    explicit StateManager(sf::RenderWindow& window);
    void pushState(std::unique_ptr<Game> state);
    void popState();
    void changeState(std::unique_ptr<Game> state);
    void update();
    void render();
    void handleEvents();
    sf::RenderWindow& window;
    std::stack<std::unique_ptr<Game>> states;
};

#endif // STATE_MANAGER_H
