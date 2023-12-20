#pragma once

#include "color.hpp"
#include <SDL2/SDL.h>
#include <cstdio>

class Object {
    int id;
    SDL_Rect rect;
    Color color;
    float velX, velY;
    float accX, accY;

public:
    Object(int x, int y, int w, int h, int r, int g, int b, int a);
    ~Object();
    SDL_Rect *getRect();
    Color getColor();
    void update();

private:
};