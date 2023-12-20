#include "prey.hpp"

Prey::Prey(int x, int y) {
    rect = {x, y, SIZE, SIZE};
    color = {0, 0, 255, 255};
    pos = {x, y};
    vel = {0, 0};
    acc = {0, 0};
}

Prey::~Prey() {
}