#pragma once

#include <cstdio>

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include "../physics/physicsHandler.hpp"

class Game {
public:
    bool isRunning = true;
    int WIDTH = 1200;
    int HEIGHT = 1200;
    const int targetFPS = 30;
    const int delayTime = 1000 / targetFPS;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    PhysicsHandler pHandler;

public:
    Game();
    ~Game();

private:
    void Run();
    void Update();
    void Draw();
    void Events();
};