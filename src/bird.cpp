#include "Bird.h"
Bird::Bird(int x, int y) {
    rect = {x, y, 40, 40};
    velocity = 0;
}
void Bird::update() {
    velocity += GRAVITY;
    rect.y += velocity;
}
void Bird::jump() {
    velocity = JUMP_STRENGTH;
}
