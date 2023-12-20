#pragma once

#include <cstdio>

#include <memory>
#include <iostream>

#include <SDL2/SDL.h>

#include "../physics/physicsHandler.hpp"
#include "../events/eventHandler.hpp"

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

    PhysicsHandler pHandler;
    //  EventHandler eHandler;

    SDL_Event event;

public:
    Game();
    ~Game();

private:
    void Run();
    void Update();
    void Draw();
};