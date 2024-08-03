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

void Button::setText(const std::string &str, const sf::Font &font) {
    text.setFont(font);
    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setPosition(sprite.getPosition().x+70,sprite.getPosition().y+10);
    text.setScale(.8,.8);
}

void Button::animate() {
    if (positionchanged > 4) {
        increment = -1;
    }
    else if(positionchanged < -4) {
        increment = 1;
    }
    sprite.move(0, .02 * increment);
    text.move(0,0.02*increment);
    positionchanged = .02 * increment + positionchanged;
}

bool Button::isClicked(int x, int y) const {
    return sprite.getGlobalBounds().contains(x,y);
}
