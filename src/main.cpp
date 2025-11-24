#include "raylib.h"
#include "player.h"
#include "ground.h"
#include <vector>
#include <cstdio>

int main(){
    InitWindow(0,0,"Raylib Test");
    ToggleFullscreen();
    SetTargetFPS(60);

    //gets the screen dimentions
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();

    Player player(100.0f,200.0f);

    Ground ground;

    //load images
    Texture2D playerTexture = LoadTexture("assets/player.png");

    //while running
    while (!WindowShouldClose()){
        //get delta time every frame and resets velocity
        float deltaTime = GetFrameTime();

        //check for keypresses
        if (IsKeyDown(KEY_RIGHT)) player.acceleration.x += 30.0f;
        if (IsKeyDown(KEY_LEFT)) player.acceleration.x += -30.0f;
        if (IsKeyDown(KEY_UP)) player.acceleration.y = -500.0f;
       
        bool col = ground.Collide(player.position.x,(player.position.y+16*player.size));

        if (col){
            player.inair = false;
            player.acceleration.y = 0.0f;


        }else player.inair = true;
            

        player.Move(deltaTime);

        player.Fall(deltaTime);
        

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(WHITE);

        //draw all the ground
        ground.Draw();

        //draw the player
        DrawTextureEx(playerTexture,player.position,0.0f,player.size,WHITE);


        //debug UI
        char debug_onground[30];
        snprintf(debug_onground, sizeof(debug_onground), "inAir: %s", player.inair ? "true": "false");
        DrawText(debug_onground, 10 , 10 ,40 , BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}