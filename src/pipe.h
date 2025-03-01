#ifndef PIPE_H
#define PIPE_H
#include <SDL2/SDL.h>
#include <cstdlib>
const int PIPE_SPEED = 5;
const int PIPE_GAP = 150;
const int PIPE_WIDTH = 80;
const int SCREEN_HEIGHT = 600;
class Pipe {
public:
    SDL_Rect top, bottom;
    Pipe(int x);
    void update();
};
#endif
