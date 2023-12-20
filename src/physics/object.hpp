#pragma once

#include "util.hpp"
#include <SDL2/SDL.h>
#include <cstdio>

const int SIZE = 50;

class Object {
private:
    int id;

public:
    SDL_Rect rect;
    Color color;
    vec2 pos, vel, acc;

public:
    Object();
    Object(int x, int y);
    Object(int x, int y, int w, int h, int r, int g, int b, int a);
    ~Object();

    void Update();
    SDL_Rect *getRect();
    Color getColor();

    vec2 getPosition();
    vec2 getNextPosition();

private:
};