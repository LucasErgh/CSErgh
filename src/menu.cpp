/*
    menu.cpp
*/

#include "menu.hpp"
#include "raylib.h"

/*
    Draw the main menu
*/
void Menu::DrawMenu(){
    const char* title = "CS Ergh\0";
    const int titleFont = 50;
    Vector2 titlePosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };

    const char* startButtonText = "Start\0";

    int padding = 50;


    BeginDrawing();
        ClearBackground(RAYWHITE);
        // DrawTextCentered({GetScreenWidth()/2.0f, GetScreenHeight()/2.0f}, title, titleFont);

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
