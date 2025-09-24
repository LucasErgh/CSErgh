/*
    game.hpp
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "screen.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "raylib.h"
#include <vector>

class Game : public Screen {
public:
    /*
        Indicates to screen that they are on top
    */
    void onTop() override;

    /*
        Game constructor
    
        @param[in] camera Reference to camera object being used
    */
    Game();

    /*
        Renders screen
    */
    void render();

    /*
        Polls events and updates screen info
    */
    ScreenCommand update();

private:
    Camera camera = { 0 };

    Vector3 mapPosition = {0, 0, 0};

    std::vector<Enemy> enemies;
    Player player;
    Vector3 testSpherePos = {0, 0, 0};
    float testSphereRadius = 3.0f;
    Color testSphereColor = RED;


    void renderHUD();

    bool getEnemyRayCollisions(int& enemyID);

    void drawHitBoxAroundCamera();
    void checkCubicMapCollision();

    void handleLeftClick();

    void spawnEnemy();
};

#endif
