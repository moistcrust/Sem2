#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "game.h"

class menu final : public Game{
public:
    sf::Texture texture;
    Button button;
    std::vector<Button> buttons;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void eventhandle(sf::RenderWindow &window) override;
    menu();
    ~menu() override;
};

#endif //MENU_H