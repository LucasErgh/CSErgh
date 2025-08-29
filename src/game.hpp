/*
    game.hpp
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "screen.hpp"
#include "raylib.h"

class Game : public Screen {
public:
    /*
        Indicates to screen that they are on top
    */
    void onTop() override;

    /*
        Game constructor
    
        @param[in] camera Reference to camera object being used
    */
    Game();

    /*
        Renders screen
    */
    void render();

    /*
        Polls events and updates screen info
    */
    ScreenCommand update();

private:
    Camera camera = { 0 };
};

#endif
