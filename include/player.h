#pragma once
#include "raylib.h"
#include "ground.h"
#include <vector>

class Player{
public:
    Texture2D standing_right;
    Vector2 position;
    int size;
    Vector2 acceleration;
    float default_acceleration;
    bool inair;
    std::vector<int> frames;
    

    Player(float x, float y);
    void Draw();
    void Move(float deltaTime);
    void Fall(float deltaTime);
    void Collide(Ground& ground);

};