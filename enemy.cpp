#include "enemy.h"

void enemy::explode() {
    explosion_sprite.setOrigin(explosion_sprite.getLocalBounds().width / 2, explosion_sprite.getLocalBounds().height / 2);
    explosion_sprite.setPosition(sprite.getPosition());
    explosion_sprite.setScale(.2, .2);
}

void enemy::move(float x, float y) {
    sprite.move(x, y);
    if (exploded) {
        explosion_sprite.move(x, y);
    }
}

enemy::enemy(sf::Texture& texture, float x, float y, float angle) {
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(x, y);
    sprite.setScale(20 / sprite.getLocalBounds().width, 20 / sprite.getLocalBounds().height);
    sprite.setRotation(angle);
    exploded = false;
}

enemy::~enemy() = default;
