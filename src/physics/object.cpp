#include "object.hpp"

Object::Object(int x, int y, int w, int h, int r, int g, int b, int a)
    : rect{x, y, w, h}, color{r, g, b, a}, pos{x, y}, vel{0, 0}, acc{0, 0} {
}

Object::~Object() {}

SDL_Rect *Object::getRect() {
    return &rect;
}

Color Object::getColor() {
    return color;
}

void Object::Update() {
    vel.x += acc.x;
    vel.y += acc.y;

    pos.x += vel.x;
    pos.y += vel.y;

    rect.x = pos.x;
    rect.y = pos.y;
}

vec2 Object::getPosition() {
    return pos;
}

vec2 Object::getNextPosition() {
    return {pos.x + vel.x + acc.x, pos.y + vel.y + acc.y};
}