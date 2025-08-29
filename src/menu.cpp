/*
    menu.cpp
*/

#include "menu.hpp"
#include "raylib.h"

Menu::Menu() {
    ui.addText(3, 0.5f, 0.1f, 0.4f, 0.2f, "CS Ergh");
    ui.addButton(1, 0.5f, 0.4f, 0.4f, 0.2f, "Start");
    ui.addButton(2, 0.5f, 0.7f, 0.4f, 0.2f, "Exit");
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
    ui.draw();
    BeginDrawing();
        ClearBackground(RAYWHITE);
        ui.draw();
    EndDrawing();
}

ScreenCommand Menu::update(){
    if(IsWindowResized()){
        // TODO - handle resize
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        int box = ui.checkMouseCollision();
        if (box == 1){
            return ScreenCommand::AddGame;
        } else if (box == 2){
            return ScreenCommand::ExitProgram;
        }

    }
    return ScreenCommand::None;
}
