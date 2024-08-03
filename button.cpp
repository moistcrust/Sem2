#include "Button.h"

Button::~Button() = default;

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
    if (positionchanged > 4) {
        increment = -1;
    }
    else if(positionchanged < -4) {
        increment = 1;
    }
    sprite.move(0, .02 * increment);
    positionchanged = .02 * increment + positionchanged;
}
