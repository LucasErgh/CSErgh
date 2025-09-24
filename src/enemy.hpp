/*
    enemy.hpp
*/

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "raylib.h"

struct Enemy{
    Vector3 position;
    int health = 100;
    static float size;
};

#endif
