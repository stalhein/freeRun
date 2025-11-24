#pragma once
#include "raylib.h"
#include "ground.h"

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
    void Collide(Ground& ground);

};