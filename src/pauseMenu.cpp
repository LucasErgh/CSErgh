/*
    pauseMenu.cpp
*/

#include "pauseMenu.hpp"
#include "raylib.h"

pauseMenu::pauseMenu() {
    ui.addButton(1, 0.5f, 0.4f, 0.35f, 0.2f, "Resume");
    ui.addButton(2, 0.5f, 0.7f, 0.35f, 0.2f, "Main Menu");
    ui.addText(3, 0.5f, 0.1f, 0.3f, 0.2f, "Game Paused");
}

/*
    Indicates to screen that they are on top
*/
void pauseMenu::onTop(){

}
/*
    Draw the main menu
*/
void pauseMenu::render(){
//    const char* title = "CS Ergh\0";
//    const int titleFont = 50;
//    Vector2 titlePosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
//
//    const char* startButtonText = "Start\0";
//
//    int padding = 50;

    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("PAUSED\0", 50, 50, 40, GREEN);
        ui.draw();
//        Vector2 textSize = MeasureTextEx(GetFontDefault(), title, titleFont, titleFont/10);
//        DrawText(title, (GetScreenWidth()/2.0f - textSize.x / 2.0f), (GetScreenHeight()/3.0f - textSize.y / 2.0f), titleFont, GRAY);
//
//        textSize = MeasureTextEx(GetFontDefault(), startButtonText, titleFont, titleFont/10);
//        DrawRectangle(
//            GetScreenWidth()/2.0f - textSize.x/2 - padding/2,
//            GetScreenHeight()*0.6f - textSize.y/2 - padding/2,
//            textSize.x + padding,
//            textSize.y + padding,
//            LIGHTGRAY
//        );
//
//        DrawText(startButtonText, (GetScreenWidth()/2.0f - textSize.x / 2.0f), (GetScreenHeight()*0.6f - textSize.y / 2.0f), titleFont, GRAY);
//
//        DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 5, RED);
    EndDrawing();
}
/*
    Scales UI elements to a ratio of the screen size
*/
void pauseMenu::scaleUIElements(){

}

ScreenCommand pauseMenu::update(){
    if(IsWindowResized()){
        // TODO - handle resize
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int buttonPresed = ui.checkMouseCollision();
        if (buttonPresed == 1)
            return ScreenCommand::RemoveScreen;
        if (buttonPresed == 2){
            return ScreenCommand::RemoveScreenTwice;
        }
    }
    return ScreenCommand::None;
}
