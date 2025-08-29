/*
    main.cpp
*/

#include "menu.hpp"
#include "raylib.h"
#include "raymath.h"

enum WindowState{
    MainMenu
};

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "Bob's Mansion");
    InitAudioDevice();
    DisableCursor();
    SetTargetFPS(60);

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 0.5f, 5.0f };
    camera.target = (Vector3){ 3.0f, 1.0f, 3.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    WindowState state = WindowState::MainMenu;

    while(!WindowShouldClose()){
        switch (state)
        {
        case WindowState::MainMenu:
            Menu::DrawMenu();
            break;

        default:
            break;
        }
    }

    CloseWindow();
}
