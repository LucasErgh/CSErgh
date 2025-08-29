/*
    UIManager.hpp
*/

#include "UIManager.hpp"

UIManager::UIManager(){

}

void UIManager::addButton(int id, float xPercent, float yPercent, float widthPercent, float heightPercent, std::string text, Color backgroundColor, Color boarderColor, Color textColor){
    buttons.push_back({ id, xPercent, yPercent, widthPercent, heightPercent, backgroundColor, boarderColor, text, textColor });
}


void UIManager::addText(int id, float xPercent, float yPercent, float widthPercent, float heightPercent, std::string text, Color textColor){
    texts.push_back({ id, xPercent, yPercent, widthPercent, heightPercent, text, textColor });
}

void UIManager::draw(){
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    for (auto& cur : buttons) {
        Rectangle r;
        r.width = cur.widthPercent * width;
        r.height = cur.heightPercent * height;
        r.x = cur.xPosPercent * width - r.width/2;
        r.y = cur.yPosPercent * height - r.height/2;

        DrawRectangleRec(r, cur.backgroundColor);
        DrawText(cur.text.c_str(), r.x + r.width/2 - MeasureText(cur.text.c_str(), fontSize)/2, r.y + r.height*0.45, fontSize, WHITE);
    }
}

int UIManager::determineFontSize(Button button){

}
