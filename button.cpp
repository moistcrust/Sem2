#include "Button.h"

Button::Button() = default;
Button::~Button() = default;

Button::Button(const sf::Texture& texture, float x, float y) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(x, y);
    isMoved = false;
}
void Button::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Button::setScale(float x, float y) {
    sprite.setScale(spritescale[0] * x, spritescale[1] * y);
}

void Button::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
}

void Button::setText(const std::string& str, const sf::Font& font) {
    text.setFont(font);
    text.setString(str);
    text.setFillColor(sf::Color::White);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setPosition(sprite.getPosition().x, sprite.getPosition().y - 10);
}

void Button::buttonMove(const float x, const float y) {
    sprite.move(x, y);
    text.move(x, y);
}

void Button::setOrigin(float x, float y) {
    sprite.setOrigin(x, y);
}

void Button::animate() {
    if (positionchanged > 5) {
        increment = -1;
    }
    else if (positionchanged < -5) {
        increment = 1;
    }
    sprite.move(0, .1 * increment);
    text.move(0, 0.1 * increment);
    positionchanged = .1 * increment + positionchanged;
}

bool Button::isClicked(int x, int y) const {
    return sprite.getGlobalBounds().contains(x, y);
}
