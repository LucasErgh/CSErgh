/*
    game.cpp
*/

#include "game.hpp"
#include "assetManager.hpp"
#include "raylib.h"

Game::Game(){
    camera.position = (Vector3){ 5.0f, 1.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

/*
    Renders screen
*/
void Game::render() {
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);
            DrawGrid(20, 1.0f);
            DrawSphere(testSpherePos, testSphereRadius, testSphereColor);

        EndMode3D();

        renderHUD();
    EndDrawing();
}

/*
    Handles events in the main menu
*/
ScreenCommand Game::update(){
    if (IsKeyPressed(KEY_ESCAPE)){
        EnableCursor();
        return ScreenCommand::AddPauseMenu;
    } if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        PlaySound(AssetManager::getInstance()->GetSound("Pew1"));
    }
    checkCollision();
    return ScreenCommand::None;
}

/*
    Indicates to screen that they are on top
*/
void Game::onTop(){
    DisableCursor();
}

void Game::renderHUD(){
    DrawTextureEx(
        AssetManager::getInstance()->GetTexture("Gun"),
        { 800, 450 },
        0.0f,
        0.5f,
        WHITE
    );

    if (hit == true){
        DrawText("HIT", 20, 20, 40, GREEN);
    }

    DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 5, WHITE);
}

void Game::checkCollision() {
    auto ray = GetScreenToWorldRay({GetScreenWidth()/2, GetScreenHeight()/2}, camera);

    RayCollision collision = { 0 };
    const char *hitObjectName = "None";
    collision.hit = false;
    Color cursorColor = WHITE;

    collision = GetRayCollisionSphere(ray, testSpherePos, testSphereRadius);
    if (collision.hit) hit = true;
    else hit = false;
}
