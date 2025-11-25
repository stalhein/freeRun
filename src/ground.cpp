#include "ground.h"
#include "raylib.h"
#include <cmath>

Ground::Ground(){
    dirtTile = LoadTexture("assets/ground/dirt.png");
    grassTile = LoadTexture("assets/ground/grass.png");
    groundScale = 4;

    groundTiles.assign({
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
        {2,2,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2}
    });

}

void Ground::Draw(){
    for (size_t i = 0; i < groundTiles.size(); i++){
        for (size_t j = 0; j < groundTiles[i].size(); j++){
            if (groundTiles[i][j] != 0){
                //convert loop index into floats
                float fi = static_cast<float>(i);
                float fj = static_cast<float>(j);

                if (groundTiles[i][j] == 1)DrawTextureEx(dirtTile,{fj*(32*groundScale),fi*(32*groundScale)},0.0f,groundScale,WHITE);
                if (groundTiles[i][j] == 2)DrawTextureEx(grassTile,{fj*(32*groundScale),fi*(32*groundScale)},0.0f,groundScale,WHITE);

                
            }
        }
    }
}

Result Ground::Collide(float px , float py){
    int tileX = std::floor(px / (32*groundScale));
    int tileY = std::floor(py / (32*groundScale));

    if (groundTiles[tileY][tileX] != 0){
        return {true ,tileX,tileY};
    }else return {false ,tileX,tileY};
}