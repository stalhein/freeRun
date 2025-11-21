#include "raylib.h"

int main(){
    InitWindow(800,600,"Raylib Test");
    SetTargetFPS(60);


    //while running
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works",190,200,20,LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}