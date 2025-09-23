/*
    assetManager.cpp
*/

#include "assetManager.hpp"

AssetManager* AssetManager::instance = nullptr;

AssetManager* AssetManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }
    return instance;
}

AssetManager::AssetManager() {
    sounds["Pew1"] = LoadSound("../assets/Pew1.wav");
    
    Image GunImage = LoadImage("../assets/Gun.png");
    textures["Gun"] = LoadTextureFromImage(GunImage);
    UnloadImage(GunImage);
}

AssetManager::~AssetManager() {
    for (auto i = sounds.begin(); i != sounds.end(); ++i) {
        UnloadSound(i->second);
    }
    for (auto i = textures.begin(); i != textures.end(); ++i) {
        UnloadTexture(i->second);
    }

    delete instance;
}

Texture2D& AssetManager::GetTexture(const std::string& name) {
    return textures[name];
}

Sound& AssetManager::GetSound(const std::string& name) {
    return sounds[name];
}
