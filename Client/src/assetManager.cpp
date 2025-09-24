/*
    assetManager.cpp
*/

#include "assetManager.hpp"
#include <cstring>

AssetManager* AssetManager::instance = nullptr;

AssetManager* AssetManager::getInstance() {
    if (instance == nullptr) {
        instance = new AssetManager();
    }
    return instance;
}

AssetManager::AssetManager() {
    sounds["Pew1"] = LoadSound(strcat(ASSETS_DIR, "/Pew1.wav\0"));

    Image GunImage = LoadImage(strcat(ASSETS_DIR, "/Gun.png\0"));
    textures["Gun"] = LoadTextureFromImage(GunImage);
    UnloadImage(GunImage);

    Image imMap = LoadImage(strcat(ASSETS_DIR, "/cubicmap.png\0"));
    textures["CubicMapTexture"] = LoadTextureFromImage(imMap);
    Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
    models["MapModel"] = LoadModelFromMesh(mesh);

    textures["MapTexture"] = LoadTexture(strcat(ASSETS_DIR, "/cubicmap_atlas.png\0"));
    models["MapModel"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textures["MapTexture"];

    imageColors["MapPixels"] = LoadImageColors(imMap);
    UnloadImage(imMap);

    sounds["Hit"] = LoadSound(strcat(ASSETS_DIR, "/hit.wav\0"));
}

AssetManager::~AssetManager() {
    for (auto i = sounds.begin(); i != sounds.end(); ++i) {
        UnloadSound(i->second);
    }
    for (auto i = textures.begin(); i != textures.end(); ++i) {
        UnloadTexture(i->second);
    }
    for (auto i = models.begin(); i != models.end(); ++i) {
        UnloadModel(i->second);
    }
    for (auto i = imageColors.begin(); i != imageColors.end(); ++i) {
        UnloadImageColors(i->second);
    }

    delete instance;
}

Model& AssetManager::GetModel(const std::string& name) {
    return models[name];
}

Texture2D& AssetManager::GetTexture(const std::string& name) {
    return textures[name];
}

Sound& AssetManager::GetSound(const std::string& name) {
    return sounds[name];
}

Color* AssetManager::GetImageColors(const std::string& name) {
    return imageColors[name];
}
