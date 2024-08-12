#ifndef MENU_H
#define MENU_H

#include "button.h"
#include "game.h"

class menu : public Game {

public:
    float bg_pos[2] = { 0,0 };
    int changestate;

    sf::Texture background_texture;
    sf::Sprite background_sprite;

    sf::Texture button_texture;
    Button button;
    std::vector<Button> buttons;
    sf::Font font;
    float buttonscale[2]{};

    sf::Texture music_texture;
    sf::Music music;
    bool isMute;
    Button music_button;

    sf::Clock menuClock;

    int mouse_pos[2]{};
    bool isMousepressed;
    bool isMousereleased;
    int click_pos_x{}, click_pos_y{};

    void update() override;
    void render() override;
    void eventhandle() override;
    int getchangestate() override;
    void animate_background();
    explicit menu(sf::RenderWindow& window);
    ~menu() override;
};

#endif //MENU_H