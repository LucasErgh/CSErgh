/*
    UIManager.hpp
*/

#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "raylib.h"
#include <vector>
#include <string>

class UIManager{
private:
    struct Text{
        int id;
        float xPercent, yPercent;
        float widthPercent, heightPercent;
        const std::string& text; 
        Color textColor = BLACK;
    };

    struct Button{
        int id;

        float xPosPercent, yPosPercent;
        float widthPercent, heightPercent;
        Color backgroundColor;
        Color boarderColor;

        std::string text;
        Color textColor;
    };

public:
    UIManager();

    /*
        Draws UI elements
    */
    void draw();

    /*
        Adds a button to the UIManager

        @param[in] id Button id that gets returned when clicked
        @param[in] xPercent Center of button as a percent of screen width
        @param[in] yPercent Center of button as a percent of screen height
        @param[in] widthPercent Width of button as a percent of screen width
        @param[in] heightPercent Height of button as a percent of screen height
        @param[in] text Text to be displayed on the button
        @param[in] backgroundColor Color of the backGround of the button
        @param[in] boarderColor color of the board of the button
        @param[in] textColor Color of the buttons text
    */
    void addButton(
        int id,
        float xPercent, float yPercent,
        float widthPercent, float heightPercent,
        std::string text,
        Color backgroundColor = LIGHTGRAY, Color boarderColor = DARKGRAY,
        Color textColor = BLACK
    );

    /*
        Adds a button to the UIManager

        @param[in] id text id that gets returned when clicked
        @param[in] xPercent Center of text as a percent of screen width
        @param[in] yPercent Center of text as a percent of screen height
        @param[in] widthPercent Width of text as a percent of screen width
        @param[in] heightPercent Height of text as a percent of screen height
        @param[in] text Text to be displayed
        @param[in] textColor Color of the text
    */
    void addText(int id, float xPercent, float yPercent, float widthPercent, float heightPercent, std::string text, Color textColor = BLACK);

    /*
        Checks if mouse collides with any interactable UI elements

        @return int Id of given button
        @retval 0 no button was hit
    */
    int checkMouseCollision();
private:
    const int fontSize = 40;
    std::vector<Text> texts;
    std::vector<Button> buttons;

    int determineFontSize(Text text);
    int determineFontSize(Button button);

};

#endif
