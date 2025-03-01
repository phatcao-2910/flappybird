#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <vector>
#include "Bird.h"
#include "Pipe.h"
const int SCREEN_WIDTH = 800;
class Game {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    Bird bird;
    std::vector<Pipe> pipes;
    Game();
    ~Game();
    void handleEvents();
    void update();
    void render();
    void run();
    bool checkCollision();
};
#endif
