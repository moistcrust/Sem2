#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const sf::Font& font, const std::string& textString);
    Button();
    sf::RectangleShape shape;
    sf::Text text;
};

#endif // BUTTON_H
