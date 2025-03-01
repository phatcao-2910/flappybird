#ifndef BIRD_H
#define BIRD_H
#include <SDL2/SDL.h>
const int GRAVITY = 1;
const int JUMP_STRENGTH = -15;
class Bird {
public:
    SDL_Rect rect;
    int velocity;
    Bird(int x, int y);
    void update();
    void jump();
};
#endif
