#include "missile.h"
#include <iostream>
#include <cmath>
#include <random>

#ifndef M_PI
#define M_PI 3.14159
#endif

void missile::eventhandle() {
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            window.close();
        }
        if (ev.type == sf::Event::MouseMoved) {
            mouse_pos[0] = ev.mouseMove.x;
            mouse_pos[1] = ev.mouseMove.y;
        }
        if (ev.type == sf::Event::KeyPressed) {
            if (ev.key.code == sf::Keyboard::Escape) {
                if (gameOver) {
                    changestate = -1;
                }
            }
        }
    }
}


void missile::update() {
    if (clock1.getElapsedTime().asMilliseconds() >= 5 and (not gameOver)) {
        float plane_angle = plane_sprite.getRotation();
        float diffX = mouse_pos[0] - plane_pos[0];
        float diffY = mouse_pos[1] - plane_pos[1];
        float toRotate = atan2(diffY, diffX) * (180 / M_PI);
        float anglediff = toRotate - plane_angle;

        if (anglediff < -180) { anglediff += 360; }
        if (anglediff > 180) { anglediff -= 360; }

        plane_sprite.rotate(rotationspeed * (anglediff > 0 ? 1.f : -1.f));

        backgroundChange();

        float bgmove_x = std::cos(plane_angle * (M_PI / 180)) * speed;
        float bgmove_y = std::sin(plane_angle * (M_PI / 180)) * speed;

        for (auto& background_sprite : background_sprites) {
            background_sprite.move(-bgmove_x, -bgmove_y);
        }
        for (auto& enemy : enemies) {
            enemy.move(-bgmove_x, -bgmove_y);
        }
        moveEnemies();
        if (isPlaneExploded) {
            float time = planeClock.getElapsedTime().asSeconds();
            if (time >= 0.65) {
                gameOver = true;
                isPlaneExploded = false;
                initgameover();
            }
            else if (time >= 0.55) {
                planeExplosionSprite.setTexture(explosion_textures[6]);
                planeexplode();
                planeExplosionSprite.setScale(1.1, 1.1);
            }
            else if (time >= 0.475) {
                planeExplosionSprite.setTexture(explosion_textures[5]);
                planeexplode();
                planeExplosionSprite.setScale(1, 1);
            }
            else if (time >= 0.4) {
                planeExplosionSprite.setTexture(explosion_textures[4]);
                planeexplode();
                planeExplosionSprite.setScale(0.9, 0.9);
            }
            else if (time >= 0.3) {
                planeExplosionSprite.setTexture(explosion_textures[3]);
                planeexplode();
                planeExplosionSprite.setScale(0.8, 0.8);
            }
            else if (time >= 0.2) {
                planeExplosionSprite.setTexture(explosion_textures[2]);
                planeexplode();
                planeExplosionSprite.setScale(0.7, 0.7);
            }
            else if (time >= 0.1) {
                planeExplosionSprite.setTexture(explosion_textures[1]);
                planeexplode();
                planeExplosionSprite.setScale(0.6, 0.6);
            }
            else {
                planeExplosionSprite.setTexture(explosion_textures[0]);
                planeexplode();
                planeExplosionSprite.setScale(0.5, 0.5);
            }
        }
    }
    if (clock2.getElapsedTime().asSeconds() >= 3 and (not gameOver)) {
        clock2.restart();
        addEnemies();
    }
    if (gameOver) {
        if (clock3.getElapsedTime().asMilliseconds() > check) {
            if (opacity==150) {
                increment = 1;
                check = 30;
            }
            if (opacity==200){increment = -1;}
            clock3.restart();
            opacity += increment;
            overlay.setFillColor(sf::Color(0, 0, 0, opacity));
            for (auto &gameovertext: gameovertexts) {
                gameovertext.setFillColor(sf::Color(255, 255, 255, opacity));
            }
        }
    }
}

void missile::render() {
    if (clock1.getElapsedTime().asMilliseconds() >= 5) {
        window.clear(sf::Color::Black);
        clock1.restart();
        for (auto& background_sprite : background_sprites) {
            window.draw(background_sprite);
        }
        for (auto& enemy : enemies) {
            window.draw(enemy.sprite);
            if (enemy.exploded) {
                window.draw(enemy.explosion_sprite);
            }
        }
        window.draw(plane_sprite);
        if (isPlaneExploded) {
            window.draw(planeExplosionSprite);
        }
        if (gameOver) {
            window.draw(overlay);
            for (auto& gameovertext: gameovertexts) {
                window.draw(gameovertext);
            }
        }
        window.display();
    }
}

void missile::addEnemies() {
    float x, y, angle;
    bool spawnOnXAxis = (getRand(1) == 0);

    if (spawnOnXAxis) {
        x = (getRand(1) == 0) ? 0 : 1200;
        y = getRand(800);
    }
    else {
        x = getRand(1200);
        y = (getRand(1) == 0) ? 0 : 800;
    }

    angle = atan2(y - plane_pos[1], x - plane_pos[0]) * (180 / M_PI);
    int n = getRand(enemy_textures.size() - 1);

    enemies.emplace_back(enemy_textures[n], x, y, 180+angle);
}

void missile::moveEnemies() {
    float diffX, diffY, toRotate, anglediff;
    int n = enemies.size();
    float time;

    for (int i = 0; i < n; i++) {
        diffX = plane_pos[0] - enemies[i].sprite.getPosition().x;
        diffY = plane_pos[1] - enemies[i].sprite.getPosition().y;
        toRotate = atan2(diffY, diffX) * (180 / M_PI);
        float currentRotation = enemies[i].sprite.getRotation();

        anglediff = toRotate - currentRotation;
        if (anglediff > 180) {
            anglediff -= 360;
        }
        if (anglediff < -180) {
            anglediff += 360;
        }

        if (std::abs(anglediff) < enemyrotationspeed) {
            enemies[i].sprite.setRotation(toRotate);
        }
        else {
            enemies[i].sprite.rotate(enemyrotationspeed * (anglediff > 0 ? 1.f : -1.f));
        }
        currentRotation = enemies[i].sprite.getRotation();
        float radians = currentRotation * (M_PI / 180);
        float X1 = enemyspeed * cos(radians);
        float Y1 = enemyspeed * sin(radians);
        enemies[i].move(X1, Y1);

        if ((pow(pow(diffX, 2) + pow(diffY, 2), .5))<=30 and (not isPlaneExploded)) {
            enemies[i].clock.restart();
            enemies[i].exploded = true;
            isPlaneExploded = true;
            planeClock.restart();
            speed = 0;
            rotationspeed = 0;
            enemyspeed = 0;
            enemyrotationspeed = 0;
        }
        else if (enemies[i].clock.getElapsedTime().asSeconds() > 11.0 && enemies.size() > 3) {
            enemies[i].clock.restart();
            enemies[i].exploded = true;
        }
        if (enemies[i].exploded) {
            time = enemies[i].clock.getElapsedTime().asSeconds();
            if (time > 0.625) {
                enemies.erase(enemies.begin() + i);
                n--;
                i--;
            }
            else if (time > 0.55) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[6]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.5, .5);
            }
            else if (time > 0.475) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[5]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.45, .45);
            }
            else if (time > 0.4) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[4]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.40, .40);
            }
            else if (time > 0.3) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[3]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.35, .35);
                enemies[i].sprite.setScale(0, 0);
            }
            else if (time > 0.2) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[2]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.30, .30);
            }
            else if (time > 0.1) {
                enemies[i].explosion_sprite.setTexture(explosion_textures[1]);
                enemies[i].explode();
                enemies[i].explosion_sprite.setScale(.25, .25);
            }
            else {
                enemies[i].explosion_sprite.setTexture(explosion_textures[0]);
                enemies[i].explode();
            }
        }
    }
}

void missile::planeexplode() {
    planeExplosionSprite.setOrigin(planeExplosionSprite.getLocalBounds().width / 2, planeExplosionSprite.getLocalBounds().height / 2);
    planeExplosionSprite.setPosition(600, 400);
    planeExplosionSprite.setScale(.5, .5);
}

void missile::initgameover() {
    overlay.setSize(sf::Vector2f(1200,800));
    overlay.setOrigin(600,400);
    overlay.setPosition(600,400);
    overlay.setFillColor(sf::Color(0,0,0,0));

    gameovertexts[0].setFont(font);
    gameovertexts[0].setString("GAME OVER");
    gameovertexts[0].setCharacterSize(50);
    gameovertexts[0].setFillColor(sf::Color(255,255,255,0));
    gameovertexts[0].setOrigin(gameovertexts[0].getLocalBounds().width/2,gameovertexts[0].getLocalBounds().height/2);
    gameovertexts[0].setPosition(600,200);

    gameovertexts[1].setFont(font);
    gameovertexts[1].setString("YOUR SCORE WAS");
    gameovertexts[1].setCharacterSize(50);
    gameovertexts[1].setFillColor(sf::Color(255,255,255,0));
    gameovertexts[1].setOrigin(gameovertexts[1].getLocalBounds().width/2,gameovertexts[1].getLocalBounds().height/2);
    gameovertexts[1].setPosition(600,400);

    gameovertexts[2].setFont(font);
    gameovertexts[2].setString("Press ESC to exit...");
    gameovertexts[2].setCharacterSize(20);
    gameovertexts[2].setFillColor(sf::Color(255,255,255,0));
    gameovertexts[2].setOrigin(gameovertexts[2].getLocalBounds().width/2,gameovertexts[2].getLocalBounds().height/2);
    gameovertexts[2].setPosition(600,700);
    clock3.restart();
}

int missile::getchangestate() {
    return changestate;
}

// ReSharper disable once CppMemberFunctionMayBeConst
void missile::backgroundChange() {
    int m = 0, n = 0;
    for (int i = 0; i < 4; i++) {
        sf::FloatRect spriteBounds = background_sprites[i].getGlobalBounds();
        if (spriteBounds.left + spriteBounds.width < 0) {
            m = 1;
        }
        else if (spriteBounds.left > window.getSize().x) {
            m = -1;
        }
        if (spriteBounds.top + spriteBounds.height < 0) {
            n = 1;
        }
        else if (spriteBounds.top > window.getSize().y) {
            n = -1;
        }
    }
    for (auto& sprite : background_sprites) {
        sprite.move(1200 * m, 800 * n);
    }
}

int missile::getRand(int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, max);
    return dis(gen);
}

void missile::initTextures() {
    int i = 0;

    plane_texture.loadFromFile("../resources/planes/planeblue1.png");
    plane_sprite.setTexture(plane_texture);

    plane_sprite.setOrigin(plane_sprite.getLocalBounds().width / 2, plane_sprite.getLocalBounds().height / 2);
    plane_sprite.setScale(50 / plane_sprite.getLocalBounds().width, 50 / plane_sprite.getLocalBounds().height);
    plane_sprite.setPosition(plane_pos[0], plane_pos[1]);

    for (auto& str : enemypng) {
        if (i < enemy_textures.size()) {
            enemy_textures[i].loadFromFile(str);
        }
        i++;
    }
    for (int i = 0; i < explosion_textures.size(); i++) {
        explosion_textures[i].loadFromFile("../resources/Explosion/explosion" + std::to_string(i) + ".png");
    }

    float j = -1;
    float k = -1;
    for (auto& background_sprite : background_sprites) {
        if (j == 1) {
            j = -1;
            k++;
        }
        background_sprite.setTexture(background_texture);
        background_sprite.setScale(1200 / background_sprite.getLocalBounds().width, 800 / background_sprite.getLocalBounds().height);
        background_sprite.setPosition(j * 1200, k * 800);
        j++;
    }
}

missile::missile(sf::RenderWindow& window) : Game(window) {
    changestate = 0;

    background_texture.loadFromFile("../resources/black.png");
    background_sprites = std::vector<sf::Sprite>(4);
    enemy_textures = std::vector<sf::Texture>(20);
    explosion_textures = std::vector<sf::Texture>(7);
    font.loadFromFile("../resources/KnightWarrior-w16n8.otf");
    gameovertexts =std::vector<sf::Text>(3);

    rotationspeed = 1.2;
    speed = 1;
    enemyrotationspeed = .5;
    enemyspeed = 1.1;
    dist_to_fire = 10;
    isPlaneExploded = false;

    initTextures();
    gameOver = false;
}


