#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "game.h"
class menu final : public Game{

public:
    float bg_pos[2] = {0,0};

    sf::Texture background_texture;
    sf::Sprite background_sprite;
    sf::Texture button_texture;

    Button button;
    std::vector<Button> buttons;
    sf::Font font;
    float buttonscale[2];

    sf::Texture music_texture;
    sf::Music music;
    Button music_button;
    bool isMute;

    int mouse_pos[2]{};
    bool isMousedpressed;

    void update(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    void eventhandle(sf::RenderWindow &window) override;
    void animate_background();
    menu();
    ~menu() override;
};

#endif //MENU_H