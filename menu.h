#ifndef MENU_H
#define MENU_H

#include "resources.h"
#include "game.h"

class menu final : public game{
    void init() override;
public:
    menu();
    void update() override;
    void render() override;
    void eventhandle() override;
    sf::Font font;
    Button button1,button2,button3;
};

#endif //MENU_H
