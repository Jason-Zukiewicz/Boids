#pragma once

#include <cstdio>

#include <iostream>
#include <memory>

#include "../physics/physicsHandler.hpp"
#include <SDL2/SDL.h>

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