#include "Game.h"
#include <ctime>
Game::Game() : bird(100, SCREEN_HEIGHT / 2) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;
    srand(time(0));
    pipes.emplace_back(SCREEN_WIDTH);
}
Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            bird.jump();
        }
    }
}
bool Game::checkCollision() {
    for (auto& pipe : pipes) {
        if (SDL_HasIntersection(&bird.rect, &pipe.top) || SDL_HasIntersection(&bird.rect, &pipe.bottom)) {
            return true;
        }
    }
    if (bird.rect.y <= 0 || bird.rect.y + bird.rect.h >= SCREEN_HEIGHT) {
        return true;
    }
    return false;
}
void Game::update() {
    bird.update();
    for (auto& pipe : pipes) {
        pipe.update();
    }
    if (!pipes.empty() && pipes.front().top.x + PIPE_WIDTH < 0) {
        pipes.erase(pipes.begin());
        pipes.emplace_back(SCREEN_WIDTH);
    }
    if (checkCollision()) {
        running = false;
    }
}
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &bird.rect);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (auto& pipe : pipes) {
        SDL_RenderFillRect(renderer, &pipe.top);
        SDL_RenderFillRect(renderer, &pipe.bottom);
    }
    SDL_RenderPresent(renderer);
}
void Game::run() {
    while (running) {
        handleEvents();
        update();
        render();
        SDL_Delay(16);
    }

}
