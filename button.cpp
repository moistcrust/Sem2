#include "button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, const sf::Font& font, const std::string& textString) {
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);

    text.setFont(font);
    text.setString(textString);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(
        x + (width - text.getLocalBounds().width) / 2,
        y + (height - text.getLocalBounds().height) / 2 - 10
    );
}

Button::Button() {
}


