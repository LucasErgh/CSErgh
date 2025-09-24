/*
    game.cpp
*/

#include "game.hpp"
#include "assetManager.hpp"
#include "raylib.h"
#include "raymath.h"
#include <random>
#include <algorithm>

Game::Game(){
    camera.position = (Vector3){ 5.0f, 0.5f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    std::srand(0);
}

/*
    Renders screen
*/
void Game::render() {
    BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
            DrawGrid(20, 1.0f);
            DrawSphere(testSpherePos, testSphereRadius, testSphereColor);

            DrawModel(AssetManager::getInstance()->GetModel("MapModel"), mapPosition, 1.0f, WHITE);
            drawHitBoxAroundCamera();

            for(const auto& cur : enemies){
                DrawSphere(cur.position, cur.size, DARKGREEN);
            }
        EndMode3D();

        renderHUD();
    EndDrawing();
}

/*
    Handles events in the main menu
*/
ScreenCommand Game::update(){
    checkCubicMapCollision();

    while (enemies.size() <= 5) {
        spawnEnemy();
    }

    if (IsKeyPressed(KEY_ESCAPE)){
        EnableCursor();
        return ScreenCommand::AddPauseMenu;
    } if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        handleLeftClick();
    }
    return ScreenCommand::None;
}

void Game::handleLeftClick(){
    PlaySound(AssetManager::getInstance()->GetSound("Pew1"));

    int enemyID;
    bool hit = getEnemyRayCollisions(enemyID);
    auto hitEnemy = std::find_if(enemies.begin(), enemies.end(), [&enemyID](const Enemy& e) { return e.id == enemyID; });

    if (hitEnemy != enemies.end()) {
        PlaySound(AssetManager::getInstance()->GetSound("Hit"));
        hitEnemy->health -= 20;
        if (hitEnemy->health <= 0) {
            enemies.erase(hitEnemy);
        }
    }
}

/*
    Indicates to screen that they are on top
*/
void Game::onTop(){
    DisableCursor();
}

void Game::renderHUD(){
    // Draw MiniMap
    int playerCellX = (int)(camera.position.x + 0.5f);
    int playerCellY = (int)(camera.position.z + 0.5f);
    Texture2D& cubicmap = AssetManager::getInstance()->GetTexture("CubicMapTexture");

    DrawTextureEx(cubicmap, (Vector2){ GetScreenWidth() - cubicmap.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);
    DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED);

    // Draw Gun
    int screenWidth  = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    float scale = 1.0f;
    Texture2D& texture = AssetManager::getInstance()->GetTexture("Gun");

    Vector2 position = {
        (screenWidth * 3.0f / 4.0f) - (texture.width * scale / 2.0f),
        screenHeight - (texture.height * scale)
    };
    DrawTextureEx(texture, position, 0.0f, scale, WHITE);

    // Draw Crosshair
    DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 5, WHITE);
}

bool Game::getEnemyRayCollisions(int& enemyID) {
    auto ray = GetScreenToWorldRay({GetScreenWidth()/2, GetScreenHeight()/2}, camera);

    RayCollision collision = { 0 };
    const char *hitObjectName = "None";
    collision.hit = false;
    Color cursorColor = WHITE;

    RayCollision mapCollision = { 0 };
    Model& map = AssetManager::getInstance()->GetModel("MapModel");
    for (int i = 0; i < map.meshCount; ++i) {
        mapCollision = GetRayCollisionMesh(ray, map.meshes[i], map.transform);
        if (mapCollision.hit && mapCollision.distance > 0) {
            collision = mapCollision;
        }
    }

    RayCollision curCollision = { 0 };
    bool hit = false;
    for (auto& enemy : enemies) {
        curCollision = GetRayCollisionSphere(ray, enemy.position, enemy.size);
        if (curCollision.hit && curCollision.distance > 0 && (collision.hit == true && curCollision.distance < collision.distance)) {
            enemyID = enemy.id;
        }
    }

    return hit;
}

void Game::drawHitBoxAroundCamera(){
    const Vector3 hitboxDimentions = {0.5f, 0.7f, 0.5f};
    const Vector3 hitboxCenter = Vector3Subtract(camera.position, {0, 0.1f, 0});

    DrawCubeWiresV(hitboxCenter, hitboxDimentions, MAROON);
}

void Game::checkCubicMapCollision() {
    Vector3 oldCamPos = camera.position;
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);

    Vector2 playerPos = { camera.position.x, camera.position.z };
    float playerRadius = 0.1f;  // Collision radius (player is modelled as a cilinder for collision)

    int playerCellX = (int)(playerPos.x - mapPosition.x + 0.5f);
    int playerCellY = (int)(playerPos.y - mapPosition.z + 0.5f);

    Texture2D& cubicmap = AssetManager::getInstance()->GetTexture("CubicMapTexture");
    Color* mapPixels = AssetManager::getInstance()->GetImageColors("MapPixels");

    // Out-of-limits security check
    if (playerCellX < 0) playerCellX = 0;
    else if (playerCellX >= cubicmap.width) playerCellX = cubicmap.width - 1;

    if (playerCellY < 0) playerCellY = 0;
    else if (playerCellY >= cubicmap.height) playerCellY = cubicmap.height - 1;

    // Check map collisions using image data and player position
    // TODO: Improvement: Just check player surrounding cells for collision
    for (int y = 0; y < cubicmap.height; y++)
    {
        for (int x = 0; x < cubicmap.width; x++)
        {
            if ((mapPixels[y*cubicmap.width + x].r == 255) &&       // Collision: white pixel, only check R channel
                (CheckCollisionCircleRec(playerPos, playerRadius,
                (Rectangle){ mapPosition.x - 0.5f + x*1.0f, mapPosition.z - 0.5f + y*1.0f, 1.0f, 1.0f })))
            {
                // Collision detected, reset camera position
                camera.position = oldCamPos;
            }
        }
    }
}

void Game::spawnEnemy() {
    Texture2D& cubicmap = AssetManager::getInstance()->GetTexture("CubicMapTexture");
    Color* mapPixels = AssetManager::getInstance()->GetImageColors("MapPixels");

    static int nextEntityID = 0;

    while (true) {
        int xPos = std::rand() % cubicmap.width;
        int zPos = std::rand() % cubicmap.height;

        if (mapPixels[zPos*cubicmap.width + xPos].r != 255) {
            Enemy enemy;
            enemy.id = nextEntityID++;
            enemy.position = {(float)xPos, 0.5f, (float)zPos};
            enemies.push_back(enemy);
            return;
        }
    }
}
