#include "object.hpp"

Object::Object(int x, int y, int w, int h, int r, int g, int b, int a)
    : rect{x, y, w, h}, color{r, g, b, a} {
}

Object::~Object() {}

SDL_Rect *Object::getRect() {
    return &rect;
}

Color Object::getColor() {
    return color;
}

void Object::update() {
    velX += accX;
    velY += accY;

    rect.x = velX;
    rect.y = velY;
}