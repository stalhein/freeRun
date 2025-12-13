#pragma once
#include "raylib.h"
#include "ground.h"
#include "animation.h"
#include <vector>

class Player{
public:
    Vector2 position;
    int size;
    int currentChunk;
    float currentChunkF;
    int lastChunk;
    Vector2 acceleration;
    float default_acceleration;
    bool inair;
    int jumpsleft;
    std::vector<int> frames;
    
    Animation animation;

    Player(float x, float y);
    void Draw();
    void Move(float deltaTime);
    void Fall(float deltaTime);
    void Collide(Ground& ground);
    void GetChunk(int lgroundScale);

};