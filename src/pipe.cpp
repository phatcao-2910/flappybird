#include "Pipe.h"
Pipe::Pipe(int x) {
    int height = rand() % (SCREEN_HEIGHT / 2) + 50;
    top = {x, 0, PIPE_WIDTH, height};
    bottom = {x, height + PIPE_GAP, PIPE_WIDTH, SCREEN_HEIGHT - height - PIPE_GAP};
}
void Pipe::update() {
    top.x -= PIPE_SPEED;
    bottom.x -= PIPE_SPEED;
}