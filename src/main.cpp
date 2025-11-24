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

    Player player(600.0f,200.0f);

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
       
        //move is for x direction fall is for y direction
        player.Move(deltaTime);
        player.Fall(deltaTime);

        //vertical collision bottom
        Result col = ground.Collide((player.position.x+13*player.size),(player.position.y+16*player.size));
        if (col.hit){
            player.inair = false;
            if (player.acceleration.y > 0.0f){
                player.acceleration.y = 0.0f;
                player.position.y = (col.y* 32 *ground.groundScale)-player.size*16;
            }
        }else player.inair = true;

        Result colRight = ground.Collide((player.position.x+14*player.size),player.position.y);
        if (colRight.hit){
            if (player.acceleration.x >= 0){
                player.acceleration.x = 0.0f;
                player.position.x = colRight.x*(32*ground.groundScale)-(14*player.size);
            }
        }

        Result colLeft = ground.Collide((player.position.x-14*player.size),player.position.y);
        if (colLeft.hit){
            if (player.acceleration.x <= 0){
                player.acceleration.x = 0.0f;
                player.position.x = colLeft.x*32*ground.groundScale;
            }
        }

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(WHITE);

        //draw all the ground
        ground.Draw();

        //debug UI
        char debug_onground[30];
        snprintf(debug_onground, sizeof(debug_onground), "inAir: %s", player.inair ? "true": "false");
        DrawText(debug_onground, 10 , 10 ,40 , BLACK);
        //debug to see what tile the player is colliding with
        DrawRectangle(col.x* 32 *ground.groundScale,col.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,RED);
        DrawRectangle(colRight.x* 32 *ground.groundScale,colRight.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,GREEN);
        DrawRectangle(colLeft.x* 32 *ground.groundScale,colLeft.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,BLUE);

        //draw the player
        DrawTextureEx(playerTexture,player.position,0.0f,player.size,WHITE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}