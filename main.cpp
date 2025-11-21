#include "raylib.h"


class Player{
public:
    Vector2 position;
    float speed;
    int size;

    Player(float x, float y) : position{x, y}, speed(300.0f), size(50) {}
};





int main(){
    InitWindow(0,0,"Raylib Test");
    ToggleFullscreen();
    SetTargetFPS(60);

    //gets the screen dimentions
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();

    Player player(100.0f,200.0f);

    //load images
    Texture2D playerTexture = LoadTexture("assets/player.png");


    //while running
    while (!WindowShouldClose()){
        //get delta time every frame and resets velocity
        float deltaTime = GetFrameTime();
        Vector2 velocity = {0.0f, 0.0f};

        //check for keypresses
        if (IsKeyDown(KEY_RIGHT)) velocity.x = 1.0f;
        if (IsKeyDown(KEY_LEFT)) velocity.x = -1.0f;
        if (IsKeyDown(KEY_DOWN)) velocity.y = 1.0f;
        if (IsKeyDown(KEY_UP)) velocity.y = -1.0f;

        //updates player position according to velocity speed and keeps it accurate to current frame
        player.position.x += velocity.x * player.speed * deltaTime;
        player.position.y += velocity.y * player.speed * deltaTime;


        //draw what is on the screen
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawTextureEx(playerTexture,player.position,0.0f, 5.0f,WHITE);

        //making a temporary ground rect
        DrawRectangle(0,screenH-100,screenW,100,GREEN);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}