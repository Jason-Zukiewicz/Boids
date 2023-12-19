#pragma once

#include <cstdio>
#include <vector>
#include <memory>
#include <iostream>
#include <random>

#include <SDL2/SDL.h>

#include "../object/object.hpp"
#include "../handler/eventHandler.hpp"

using std::vector;

class Game
{
public:
    bool isRunning = true;
    int frameRate = 60;
    int WIDTH = 800;
    int HEIGHT = 600;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    vector<Object> objs;
    //PhysicsHandler pHandler;
    EventHandler handler;
    SDL_Event event;

public:
    Game();
    ~Game();

private:
    void Run();
    void Update();
    void Draw();
};