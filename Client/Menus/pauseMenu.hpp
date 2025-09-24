/*
    pauseMenu.hpp
*/

#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP

#include "screen.hpp"
#include "UIManager.hpp"
#include "raylib.h"

class pauseMenu : public Screen {
public:
    /*
        Indicates to screen that they are on top
    */
    void onTop() override;

    /*
        Constructor
    */
    pauseMenu();

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
    UIManager ui;

    /*
        Scales UI elements to a ratio of the screen size
    */
   void scaleUIElements();
};

#endif