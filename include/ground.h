#pragma once
#include "raylib.h"
#include <vector>

struct Result {
    bool hit;
    float x;
    float y;
};

class Ground{
public:
    Texture2D dirtTile;
    float groundScale;
    std::vector<std::vector<int>> groundTiles;

    Ground();
    void Draw();
    Result Collide(float px, float py);
};