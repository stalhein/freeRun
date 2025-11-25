#include "player.h"
#include "ground.h"
#include "raylib.h"
#include "animation.h"

Player::Player(float x, float y){
    standing_right = LoadTexture("assets/player.png");
    
    position = {x,y};
    size = 5;
    default_acceleration = 10.0f;
    acceleration = {0.0f,default_acceleration};
    inair = false;
}

void Player::Draw(){
    DrawTextureEx(standing_right,position,0.0f,size,WHITE);
}

void Player::Move(float deltaTime){
    position.x += acceleration.x * deltaTime;
    if (acceleration.x > 29.0f || acceleration.x < -29.0f || inair){
        if (acceleration.x < 0.0f){
            acceleration.x += 25.0f;
        }else acceleration.x -= 25.0f;
    }else acceleration.x = 0.0f;
}

void Player::Fall(float deltaTime){
    position.y += acceleration.y * deltaTime;
    acceleration.y += 3000.0f * deltaTime;
}

void Player::Collide(Ground& ground){
    Result col = ground.Collide((position.x+14*size/2),(position.y+16*size));
        if (col.hit){
            inair = false;
            if (acceleration.y > 0.0f){
                acceleration.y = 0.0f;
                position.y = (col.y* 32 *ground.groundScale)-size*16;
            }
        }else inair = true;
        //right collision
        Result colRight = ground.Collide((position.x+14*size),position.y+16*size-1);
        if (colRight.hit){
            if (acceleration.x >= 0){
                acceleration.x = 0.0f;
                position.x = colRight.x*(32*ground.groundScale)-(14*size);
            }
        }
        //left collision
        Result colLeft = ground.Collide((position.x),position.y+16*size-1);
        if (colLeft.hit){
            if (acceleration.x <= 0){
                acceleration.x = 0.0f;
                position.x = colLeft.x*(32*ground.groundScale)+(25*size);
            }
        }
}