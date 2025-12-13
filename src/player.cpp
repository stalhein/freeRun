#include "player.h"
#include "ground.h"
#include "raylib.h"
#include "animation.h"

Player::Player(float x, float y)
    : animation({//all frames for player are loaded here
        LoadTexture("assets/player/player.png"),
        LoadTexture("assets/player/player_left.png"),
        LoadTexture("assets/player/player_left_walk.png"),
        LoadTexture("assets/player/player_right.png"),
        LoadTexture("assets/player/player_right_walk.png"),
        LoadTexture("assets/player/player_jump.png")
    })
{
    position = {x,y};
    size = 5;
    default_acceleration = 10.0f;
    acceleration = {0.0f,default_acceleration};
    inair = false;
    currentChunk = 0;
    lastChunk = currentChunk;
    currentChunkF = 0.0f;
    jumpsleft = 2;
}

void Player::Draw(){
    DrawTextureEx(animation.currentFrame,position,0.0f,size,WHITE);
}

void Player::Move(float deltaTime){
    position.x += acceleration.x * deltaTime;
    if (acceleration.x > 29.0f || acceleration.x < -29.0f || inair){
        if (acceleration.x < 0.0f){
            animation.InitAnimate({1,2}, 15);
            acceleration.x += 25.0f;
        }else {
            animation.InitAnimate({3,4}, 15);
            acceleration.x -= 25.0f; 
        }
        animation.Animate();
    }else {
        acceleration.x = 0.0f;
    }
}

void Player::Fall(float deltaTime){
    if (inair && (acceleration.x < 29.0f && acceleration.x > -29.0f)) animation.ChangeFrame(5);
    position.y += acceleration.y * deltaTime;
    acceleration.y += 3000.0f * deltaTime;
    if (!inair && acceleration.x == 0)animation.ChangeFrame(0);
}

void Player::Collide(Ground& ground){
    Result col = ground.Collide((position.x+14*size/2),(position.y+16*size),(position.x+size*16/2) / (32 * ground.groundScale * 6));
        if (col.hit){
            inair = false;
            if (acceleration.y > 0.0f){
                acceleration.y = 0.0f;
                position.y = (col.y* 32 *ground.groundScale)-size*16;
            }
        }else inair = true;
        //right collision
        Result colRight = ground.Collide((position.x+14*size),position.y+16*size-1,(position.x+size*14) / (32 * ground.groundScale * 6));
        if (colRight.hit){
            if (acceleration.x >= 0){
                acceleration.x = 0.0f;
                position.x = colRight.x*(32*ground.groundScale)-(14*size);
            }
        }
        //left collision
        Result colLeft = ground.Collide((position.x),position.y+16*size-1,currentChunkF);
        if (colLeft.hit){
            if (acceleration.x <= 0){
                acceleration.x = 0.0f;
                position.x = colLeft.x*(32*ground.groundScale)+(25*size);
            }
        }
}

void Player::GetChunk(int lgroundScale){
    //find the chunk the player is in 
    currentChunkF = (position.x) / (32 * lgroundScale * 6);
    currentChunk = static_cast<int>(currentChunkF);
}