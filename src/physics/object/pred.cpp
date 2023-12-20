#include "pred.hpp"

Pred::Pred(int x, int y) {
    rect = {x, y, SIZE, SIZE};
    color = {255, 0, 0, 255};
    pos = {x, y};
    vel = {0, 0};
    acc = {0, 0};
}

Pred::~Pred() {
}