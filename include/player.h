#pragma once
#include "raylib.h"

class Player{
public:
    Vector2 position;
    int size;
    Vector2 acceleration;
    float default_acceleration;
    bool inair;
    

    Player(float x, float y);
    void Move(float deltaTime);
    void Fall(float deltaTime);
    void Jump(float deltaTime);

};