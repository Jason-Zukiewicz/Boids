#pragma once

#include <cstdio>

#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

#include "../physics/physicsHandler.hpp"

class Game {
public:
    bool isRunning = true;
    int WIDTH = 800;
    int HEIGHT = 600;
    const int targetFPS = 30;
    const int delayTime = 1000 / targetFPS;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    PhysicsHandler pHandler;

    typedef void (*quit_handler_t)(void);
    typedef void (*keydown_handler_t)(SDL_Keycode);
    typedef void (*keyup_handler_t)(SDL_Keycode);

    struct {
        quit_handler_t quit;
        keydown_handler_t keydown;
        keyup_handler_t keyup;
    } event_handlers;

public:
    Game();
    ~Game();

private:
    void Run();
    void Update();
    void Draw();
    void Events();
};