/*
    menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include "screen.hpp"
#include "raylib.h"

class Menu : public Screen {
public:
    /*
        Indicates to screen that they are on top
    */
    void onTop() override;

    /*
        Constructor
    */
    Menu();

    /*
        Draw the main menu
    */
    void render() override;

    /*
        Handles events in the main menu
    */
    ScreenCommand update() override;

private:
    Vector2 titlePos;
    Rectangle startBox;
    Rectangle exitBox;
    Rectangle optionsBox;
    int fontSize = 50;
    int padding = 50;
};

#endif
