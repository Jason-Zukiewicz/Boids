#pragma once

#include "../util.hpp"
#include <SDL2/SDL.h>
#include <cmath>
#include <cstdio>
#include <random>
#include <vector>

using std::vector;

class Object {
private:
    int id;

public:
    vector<SDL_Vertex> verts;
    SDL_FPoint pos, vel, acc;

public:
    Object();
    Object(int x, int y);
    Object(int x, int y, int r, int g, int b, int a);
    Object(SDL_FPoint point, SDL_Color color);
    virtual ~Object();

    virtual void Update();
    vector<SDL_Vertex> *getVerts();

    SDL_FPoint getPosition();
    SDL_FPoint getNextPosition();

private:
};