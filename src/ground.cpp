#include "ground.h"
#include "raylib.h"
#include <cmath>

Ground::Ground(){
    dirtTile = LoadTexture("assets/ground/dirt.png");
    groundScale = 4;

    groundTiles.assign({
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    });

}

void Ground::Draw(){
    for (size_t i = 0; i < groundTiles.size(); i++){
        for (size_t j = 0; j < groundTiles[i].size(); j++){
            if (groundTiles[i][j] != 0){
                //convert loop index into floats
                float fi = static_cast<float>(i);
                float fj = static_cast<float>(j);

                DrawTextureEx(dirtTile,{fj*(32*groundScale),fi*(32*groundScale)},0.0f,groundScale,WHITE);
            }
        }
    }
}

bool Ground::Collide(float px , float py){
    int tileX = std::floor(px / (32*groundScale));
    int tileY = std::floor(py / (32*groundScale));

    if (groundTiles[tileY][tileX] != 0){
        return true;
    }else{return false;}
}