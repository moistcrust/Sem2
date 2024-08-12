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
    float spritescale[2]{ 1,1 };

    Button(const sf::Texture& texture, float x, float y);
    void setPosition(float x, float y);
    virtual void setScale(float x, float y);
    void setTexture(const sf::Texture& texture);
    void setText(const std::string& str, const sf::Font& font);
    void buttonMove(float x, float y);
    void setOrigin(float x, float y);

    virtual void animate(); //overridable

    bool isClicked(int x, int y) const;
private:
    float positionchanged = 0;
    float increment = 1;
};

#endif // BUTTON_HPP
