#pragma once
#include "raylib.h"
#include <vector>



class Ground{
private:
    float groundScale;
public:
    Texture2D dirtTile;
    std::vector<std::vector<int>> groundTiles;

    Ground();
    void Draw();
    bool Collide(float px, float py);
};