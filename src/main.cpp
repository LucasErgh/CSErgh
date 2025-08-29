/*
    main.cpp
*/

#include "game.hpp"
#include "pauseMenu.hpp"
#include "screen.hpp"
#include "menu.hpp"
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <memory>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "CS Ergh");
    InitAudioDevice();
    SetTargetFPS(60);

    std::vector<std::unique_ptr<Screen>> screenStack;
    screenStack.push_back(std::make_unique<Menu>());

    bool exitLoop = false;

    while(!WindowShouldClose() && !exitLoop){
        ScreenCommand cmd = screenStack.back()->update();
        switch (cmd)
        {
        case ScreenCommand::RemoveScreenTwice:
            screenStack.pop_back();
        case ScreenCommand::RemoveScreen:
            screenStack.pop_back();
            screenStack.back()->onTop();
            break;
        case ScreenCommand::AddOptions:
            break;
        case ScreenCommand::AddMenu:
            break;
        case ScreenCommand::AddPauseMenu:
            screenStack.push_back(std::make_unique<pauseMenu>());
            break;
        case ScreenCommand::AddGame:
            screenStack.push_back(std::make_unique<Game>());
            screenStack.back()->onTop();
            break;
        case ScreenCommand::ExitProgram:
            exitLoop = true;
        case ScreenCommand::None:
            break;
        default:
            break;
        }
        screenStack.back()->render();
    }

    CloseWindow();
}
