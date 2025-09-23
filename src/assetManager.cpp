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

    Image imMap = LoadImage("../assets/cubicmap.png");
    textures["CubicMapTexture"] = LoadTextureFromImage(imMap);
    Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
    models["MapModel"] = LoadModelFromMesh(mesh);

    textures["MapTexture"] = LoadTexture("../assets/cubicmap_atlas.png");
    models["MapModel"].materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textures["MapTexture"];

    imageColors["MapPixels"] = LoadImageColors(imMap);
    UnloadImage(imMap);
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
