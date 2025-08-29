/*
    menu.cpp
*/

#include "menu.hpp"
#include "raylib.h"

Menu::Menu() {
    float widthCenter = GetScreenWidth()/2.0f;
    titlePos = { widthCenter, GetScreenHeight()/2.0f };

    Vector2 textSize = MeasureTextEx(GetFontDefault(), "Start\0", fontSize, fontSize/10);
    startBox = {widthCenter - textSize.x/2 - padding/2, GetScreenHeight()*0.6f - textSize.y/2 - padding/2, textSize.x + padding, textSize.y + padding};
}

/*
    Indicates to screen that they are on top
*/
void Menu::onTop(){

}
/*
    Draw the main menu
*/
void Menu::render(){
    const char* title = "CS Ergh\0";
    const int titleFont = 50;
    Vector2 titlePosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };

    const char* startButtonText = "Start\0";

    int padding = 50;

    BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 textSize = MeasureTextEx(GetFontDefault(), title, titleFont, titleFont/10);
        DrawText(title, (GetScreenWidth()/2.0f - textSize.x / 2.0f), (GetScreenHeight()/3.0f - textSize.y / 2.0f), titleFont, GRAY);

        textSize = MeasureTextEx(GetFontDefault(), startButtonText, titleFont, titleFont/10);
        DrawRectangle(
            GetScreenWidth()/2.0f - textSize.x/2 - padding/2,
            GetScreenHeight()*0.6f - textSize.y/2 - padding/2,
            textSize.x + padding,
            textSize.y + padding,
            LIGHTGRAY
        );

        DrawText(startButtonText, (GetScreenWidth()/2.0f - textSize.x / 2.0f), (GetScreenHeight()*0.6f - textSize.y / 2.0f), titleFont, GRAY);

        DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, 5, RED);
    EndDrawing();
}

ScreenCommand Menu::update(){
    if(IsWindowResized()){
        // TODO - handle resize
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        if (CheckCollisionPointRec(mousePos, startBox))
            return ScreenCommand::AddGame;
    }
    return ScreenCommand::None;
}
