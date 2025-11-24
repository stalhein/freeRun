#include "raylib.h"
#include "player.h"
#include "ground.h"
#include <vector>
#include <cstdio>

bool debug_mode = false;

int main(){
    InitWindow(0,0,"Raylib Test");
    ToggleFullscreen();
    SetTargetFPS(60);

    //gets the screen dimentions
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();

    Player player(600.0f,200.0f);

    Ground ground;

    //load images
    Texture2D playerTexture = LoadTexture("assets/player.png");

    //while running
    while (!WindowShouldClose()){
        //get delta time every frame and resets velocity
        float deltaTime = GetFrameTime();

        //check for keypresses
        if (IsKeyPressed(KEY_ZERO)) debug_mode = !debug_mode;

        if (IsKeyDown(KEY_RIGHT)) player.acceleration.x += 30.0f;
        if (IsKeyDown(KEY_LEFT)) player.acceleration.x += -30.0f;
        if (IsKeyDown(KEY_UP)) player.acceleration.y = -500.0f;
       
        //move is for x direction fall is for y direction
        player.Move(deltaTime);
        player.Fall(deltaTime);

        //vertical collision bottom
        player.Collide(ground);

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(WHITE);

        //draw all the ground
        ground.Draw();

        //debug UI
        if (debug_mode){
            char debug_onground[30];
            snprintf(debug_onground, sizeof(debug_onground), "inAir: %s", player.inair ? "true": "false");
            DrawText(debug_onground, 10 , 10 ,40 , BLACK);
            //debug to see what tile the player is colliding with
            //DrawRectangle(col.x* 32 *ground.groundScale,col.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,RED);
            //DrawRectangle(colRight.x* 32 *ground.groundScale,colRight.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,GREEN);
            //DrawRectangle(colLeft.x* 32 *ground.groundScale,colLeft.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,BLUE);
        }

        //draw the player
        DrawTextureEx(playerTexture,player.position,0.0f,player.size,WHITE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}