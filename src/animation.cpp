#include "raylib.h"
#include "animation.h"

Animation::Animation(std::vector<Texture2D> states_import){
    states = states_import;
    currentFrame = states[0];
}

void Animation::ChangeFrame(int change){
    currentFrame = states[change];
}