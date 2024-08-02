#ifndef MENU_H
#define MENU_H

#include "button.h"
#include "game.h"

class menu final : public game{
public:
    menu();
    void update(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    void eventhandle(sf::RenderWindow &window) override;

    menu(const sf::RenderWindow &window);
    sf::Font font;
    Button button1,button2,button3;
};

#endif //MENU_H
