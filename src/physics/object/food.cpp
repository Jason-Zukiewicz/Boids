#include "food.hpp"

Food::Food(int x, int y) {
    rect = {x, y, SIZE, SIZE};
    color = {0, 255, 0, 255};
    pos = {x, y};
    vel = {0, 0};
    acc = {0, 0};
}

Food::~Food() {
}