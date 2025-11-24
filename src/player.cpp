#include "player.h"
#include "ground.h"

Player::Player(float x, float y){
    position = {x,y};
    size = 5;
    default_acceleration = 10.0f;
    acceleration = {0.0f,default_acceleration};
    inair = false;
}

void Player::Move(float deltaTime){
    position.x += acceleration.x * deltaTime;
    if (acceleration.x != 0.0f){
        if (acceleration.x < 0.0f){
            acceleration.x += 20.0f;
        }else acceleration.x -= 20.0f;
    }
}

void Player::Fall(float deltaTime){
    position.y += acceleration.y * deltaTime;
    acceleration.y += 50.0f;
}

void Player::Collide(Ground& ground){
    Result col = ground.Collide((position.x+13*size/2),(position.y+16*size));
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
                position.x = colLeft.x*(32*ground.groundScale)+(30*ground.groundScale);
            }
        }
}