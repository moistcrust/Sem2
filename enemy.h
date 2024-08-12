#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class enemy {
public:
    std::vector<std::string> enemies;
    sf::Sprite sprite;
    sf::Sprite explosion_sprite;
    sf::Clock clock;
    bool exploded;

    void explode();
    void move(float x, float y);

    explicit enemy(sf::Texture& texture, float x, float y,float angle);
    ~enemy();
};



#endif //ENEMY_H
