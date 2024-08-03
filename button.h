#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    sf::Sprite sprite;
    Button();

    Button(const sf::Texture &texture, float x , float y,float widthscale,float heightscale );
    void setPosition(float x, float y);
    void setScale(float x, float y);
    void setTexture(const sf::Texture &texture);

    void animate();
private:
    float positionchanged = 0;
    float increment = .01;
};

#endif // BUTTON_HPP
