#ifndef MISSILE_H
#define MISSILE_H

#include "game.h"
#include "enemy.h"

class missile final : public Game {
public:

    int changestate;

    sf::Texture plane_texture;
    sf::Sprite plane_sprite;
    sf::Sprite planeExplosionSprite;

    sf::Texture background_texture;
    std::vector<sf::Sprite> background_sprites;


    std::vector<enemy> enemies;

    sf::Sound music;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock planeClock;
    sf::Font font;
    bool isPlaneExploded;
    bool gameOver;


    float rotationspeed;
    float speed;
    float enemyspeed;
    float enemyrotationspeed;
    float plane_pos[2]{ 600,400 };
    float dist_to_fire;
    float mouse_pos[2]{ 0,0 };
    int fire[2]{ 0,1 };

    sf::RectangleShape overlay;
    std::vector<sf::Text> gameovertexts;
    unsigned char opacity = 0;
    unsigned char increment = 1;
    int check = 10;

    std::vector<std::string> enemypng =
    { "../resources/Enemies/enemyBlack1.png",
    "../resources/Enemies/enemyBlack2.png",
    "../resources/Enemies/enemyBlack3.png",
    "../resources/Enemies/enemyBlack4.png",
    "../resources/Enemies/enemyBlack5.png",
    "../resources/Enemies/enemyBlue1.png",
    "../resources/Enemies/enemyBlue2.png",
    "../resources/Enemies/enemyBlue3.png",
    "../resources/Enemies/enemyBlue4.png",
    "../resources/Enemies/enemyBlue5.png",
    "../resources/Enemies/enemyGreen1.png",
    "../resources/Enemies/enemyGreen2.png",
    "../resources/Enemies/enemyGreen3.png",
    "../resources/Enemies/enemyGreen4.png",
    "../resources/Enemies/enemyGreen5.png",
    "../resources/Enemies/enemyRed1.png",
    "../resources/Enemies/enemyRed2.png",
    "../resources/Enemies/enemyRed3.png",
    "../resources/Enemies/enemyRed4.png",
    "../resources/Enemies/enemyRed5.png" };
    std::vector<sf::Texture> explosion_textures;
    std::vector<sf::Texture> enemy_textures;

    void initTextures();
    void backgroundChange();

    void eventhandle() override;
    void update() override;
    void render() override;

    void addEnemies();
    void moveEnemies();

    void planeexplode();

    void initgameover();
    int getchangestate() override;
    
    static int getRand(int max);

    explicit missile(sf::RenderWindow& );
};



#endif //MISSILE_H
