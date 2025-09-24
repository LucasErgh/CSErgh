/*
    player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

struct Player{
    Vector3 position;
    Vector3 velocity;
    BoundingBox hitbox;
    int health;
};

#endif
