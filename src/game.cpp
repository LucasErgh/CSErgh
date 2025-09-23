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
            DrawSphere({ 0, 0, 0 }, 3, RED);

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
}
