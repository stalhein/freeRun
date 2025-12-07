#include "ground.h"
#include "raylib.h"
#include "chunks.h"
#include <cmath>
#include <random>

Ground::Ground(){
    dirtTile = LoadTexture("assets/ground/dirt.png");
    grassTile = LoadTexture("assets/ground/grass.png");
    groundScale = 4;
    position = {0,0};
    chunkDistance = 0;


    for (int i = 0; i < 8; i++){
        genChunk(true);
    }
}

void Ground::Draw(){
    for (size_t a = 0; a < chunksInUse.size(); a++){
        for (size_t i = 0; i < chunksInUse[a].size(); i++){
            for (size_t j = 0; j < chunksInUse[a][i].size(); j++){
                if (chunksInUse[a][i][j] != 0){
                    //convert loop index into floats
                    float fi = static_cast<float>(i);
                    float fj = static_cast<float>(j);
                    float chunkWidth = chunksInUse[a][i].size() * 32 * groundScale;

                    if (chunksInUse[a][i][j] == 1)DrawTextureEx(dirtTile,{fj*(32*groundScale)+position.x + (a+chunkDistance) * chunkWidth,fi*(32*groundScale)+position.y},0.0f,groundScale,WHITE);
                    if (chunksInUse[a][i][j] == 2)DrawTextureEx(grassTile,{fj*(32*groundScale)+position.x + (a+chunkDistance) * chunkWidth,fi*(32*groundScale)+position.y},0.0f,groundScale,WHITE);

                    
                }
            }
        }
    }
}

Result Ground::Collide(float px, float py, float chunkX ){
    int tileX = std::floor(px / (32*(groundScale-position.x)));
    int tileY = std::floor(py / (32*(groundScale-position.y)));

    int internalX = static_cast<int>((chunkX - static_cast<int>(chunkX)) * 6.0f);

    if (chunksInUse[2][tileY][internalX] != 0){
        return {true ,tileX,tileY};
    }else return {false ,tileX,tileY};
}

void Ground::genChunk(bool startMode){
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> dist(0, chunks::array.size() -1);

    if (!startMode){
        chunksInUse.erase(chunksInUse.begin());
        chunkDistance ++;
    }
    chunksInUse.push_back(chunks::array[dist(gen)]);

}