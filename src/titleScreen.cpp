/*
    titleScreen.cpp
*/

#include "titleScreen.hpp"
#include "raylib.h"

TitleScreen::TitleScreen(){
    ui.addText(1, 0.5f, 0.4f, 0.4f, 0.3f, "CS Ergh");
    ui.addText(1, 0.5f, 0.6f, 0.4f, 0.3f, "Press space to continue");
}

void TitleScreen::render(){
    BeginDrawing();
        ClearBackground(RAYWHITE);
        ui.draw();
    EndDrawing();
}

ScreenCommand TitleScreen::update() {
    if (IsKeyDown(KEY_ESCAPE)) {
        return ScreenCommand::ExitProgram;
    } else if (IsKeyDown(KEY_SPACE)) {
        return ScreenCommand::AddMenu;
    }
    return ScreenCommand::None;
}

void TitleScreen::onTop(){

}
