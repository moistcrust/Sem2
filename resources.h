#ifndef RESOURCES_H
#define RESOURCES_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const sf::Font& font, const std::string& textString);
    Button();
    bool isHovered(const sf::Vector2f& mousePos) const;
    sf::RectangleShape shape;
    sf::Text text;
};

#endif // RESOURCES_H
