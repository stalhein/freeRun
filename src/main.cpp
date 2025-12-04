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

    const Color SKY = {139, 185, 201, 255};

    Player player(100.0f,1000.0f);

    Ground ground;

    //adding the camera
    Camera2D camera =  {0};
    camera.target = {player.position.x + (player.size*16)/2, player.position.y + (player.size*16)/2};
    camera.offset = { screenW/2.0f, screenH/2.0f};
    camera.zoom = 1.2f;

    //while running
    while (!WindowShouldClose()){
        //get delta time every frame and resets velocity
        float deltaTime = GetFrameTime();

        //check for keypresses
        if (IsKeyPressed(KEY_ZERO)) debug_mode = !debug_mode;

        if (IsKeyDown(KEY_RIGHT)) player.acceleration.x += 35.0f;
        if (IsKeyDown(KEY_LEFT)) player.acceleration.x += -35.0f;
        if (IsKeyDown(KEY_UP)) if (!player.inair) player.acceleration.y = -1500.0f;

        if (IsKeyDown(KEY_EQUAL)) camera.zoom += 0.1f;
        if (IsKeyDown(KEY_MINUS)) camera.zoom -= 0.1f;

        //for testing gen a new chunk with this key
        if (IsKeyPressed(KEY_NINE)) ground.genChunk();

        //move is for x direction fall is for y direction
        player.Move(deltaTime);
        //player.Fall(deltaTime);

        //gets the current chunk the player is in
        player.GetChunk(ground.groundScale);

        //the player collsion
        //player.Collide(ground);

        //sets the camera target to the new player position
        camera.target = {player.position.x + (player.size*16) /2, player.position.y + (player.size*16)/2};

        //draw what is on the screen
        BeginDrawing();
        ClearBackground(SKY);

        BeginMode2D(camera);

        //draw all the ground
        ground.Draw();

        //draw the player
        player.Draw();

        EndMode2D();//end of drawing in the world

        // draw the debug stuff AFTER the camera is off so it draws to a set place on the screen
        //This  stuff is fro DEBUGGING PRESS [0] to enable debugging menu unside the game
        if (debug_mode){
            char debug_onground[30];
            snprintf(debug_onground, sizeof(debug_onground), "inAir: %s", player.inair ? "true": "false");
            DrawText(debug_onground, 10 , 10 ,40 , BLACK);
            char debug_whatChunk[30];
            snprintf(debug_whatChunk, sizeof(debug_whatChunk), "Chunk: %d", player.currentChunk);
            DrawText(debug_whatChunk, 10 , 40 ,40 , BLACK);
            //Result col = ground.Collide((player.position.x+13*player.size/2),(player.position.y+16*player.size));
            //Result colRight = ground.Collide((player.position.x+14*player.size),player.position.y+16*player.size-1);
            //Result colLeft = ground.Collide((player.position.x),player.position.y+16*player.size-1);
            //debug to see what tile the player is colliding with
            //these need to be inside the camera placement
            BeginMode2D(camera);
            //DrawRectangle(col.x* 32 *ground.groundScale,col.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,RED);
            //DrawRectangle(colRight.x* 32 *ground.groundScale,colRight.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,GREEN);
            //DrawRectangle(colLeft.x* 32 *ground.groundScale,colLeft.y* 32 *ground.groundScale,32*ground.groundScale,32*ground.groundScale,BLUE);
            player.Draw();
            EndMode2D();
        }

        //END OF THE DRAWING
        EndDrawing();
    }

    CloseWindow();
    return 0;
}