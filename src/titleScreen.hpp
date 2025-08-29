/*
    titleScreen.hpp
*/

#ifndef TITLESCREEN_HPP
#define TITLESCREEN_HPP

#include "screen.hpp"
#include "UIManager.hpp"
#include "raylib.h"

class TitleScreen : public Screen {
public:
    /*
        Indicates to screen that they are on top
    */
    void onTop() override;

    /*
        Constructor
    */
    TitleScreen();

    /*
        Draw the main menu
    */
    void render() override;

    /*
        Handles events in the main menu
    */
    ScreenCommand update() override;

private:
    UIManager ui;
};

#endif
