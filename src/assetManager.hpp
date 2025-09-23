/*
    assetManager.hpp
*/

#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include "raylib.h"
#include <string>
#include <unordered_map>


class AssetManager {
public:
    static AssetManager* getInstance();

    ~AssetManager();

    Texture2D& GetTexture(const std::string& name);
    Sound& GetSound(const std::string& name);
private:
    AssetManager();

    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    static AssetManager* instance;

    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, Sound> sounds;
};

#endif
