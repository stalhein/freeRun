#include "player.h"

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

void Player::Jump(float deltaTime){

}