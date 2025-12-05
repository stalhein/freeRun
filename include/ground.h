#pragma once
#include "raylib.h"
#include <vector>
#include <random>

struct Result {
    bool hit;
    float x;
    float y;
};

class Ground{
public:
    Texture2D dirtTile;
    Texture2D grassTile;
    float groundScale;
    int chunkDistance;
    Vector2 position;
    std::vector<std::vector<int>> groundTiles;
    std::vector<std::vector<std::vector<int>>> chunksInUse;
    std::random_device seed;

    Ground();
    void Draw();
    Result Collide(int pcX, float pcXF , float py);
    void genChunk(bool startMode = false);
};