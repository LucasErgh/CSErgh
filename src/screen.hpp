/*
    screenStack.hpp
*/

#ifndef SCREENSTACK_HPP
#define SCREENSTACK_HPP

enum ScreenCommand{
    RemoveScreen,
    AddOptions,
    AddMenu,
    AddGame,
    AddPauseMenu,
    None
};

class Screen {
public:
    /*
        Poll events and update screen information
    */
    virtual ScreenCommand update() = 0;

    /*
        Draw screen
    */
    virtual void render() = 0;

    /*
        Indicates to screen that they are on top
    */
    virtual void onTop() = 0;

    virtual ~Screen() = default;
};

#endif
