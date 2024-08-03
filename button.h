#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    Button();

    virtual ~Button();

    sf::Text text;
    sf::Sprite sprite;
    bool isMoved{};

    Button(const sf::Texture &texture, float x , float y,float widthscale,float heightscale );
    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setTexture(const sf::Texture &texture);
    void setText(const std::string &str, const sf::Font &font);
    void buttonMove(const float x, const float y) {
        sprite.move(x,y);
    }
    virtual void animate(); //overridable

    bool isClicked(int x, int y) const;
private:
    float positionchanged = 0;
    float increment = 1;
};

#endif // BUTTON_HPP
