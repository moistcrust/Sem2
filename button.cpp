#include "Button.h"

Button::Button() = default;

Button::Button(const sf::Texture& texture, float x, float y, float widthscale = 1, float heightscale = 1) {
    sprite.setTexture(texture);
    sprite.setPosition(x , y);
    sprite.setScale(widthscale,heightscale);
}
void Button::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Button::setScale(float x, float y) {
    sprite.setScale(x,y);
}

void Button::setTexture(const sf::Texture &texture) {
    sprite.setTexture(texture);
}

void Button::animate() {
    if (positionchanged > 2) {
        increment = -0.01;
    }
    else if(positionchanged < -2) {
        increment = 0.01;
    }
    sprite.move(0,increment);
    positionchanged = increment + positionchanged;
}
