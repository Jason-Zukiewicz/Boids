#include "game.hpp"

Game::Game() : isRunning(true), window(nullptr), renderer(nullptr), pHandler(WIDTH, HEIGHT) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("[ERROR] Could Not INIT SDL\n");
        return;
    }

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    if (!window) {
        printf("[ERROR] Could Not Create Window\n");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window) {
        printf("[ERROR] Could Not Create Renderer\n");
        return;
    }

    Run();
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Run() {
    Uint32 frameStart;
    int frameTime;
    while (isRunning) {
        frameStart = SDL_GetTicks();

        Events();
        Update();
        Draw();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < delayTime) {
            SDL_Delay(delayTime - frameTime); // Delay remaining time to control FPS
        }
    }
}

void Game::Update() {
    pHandler.Update();
}

void Game::Draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    vector<Object *> *objsPtr = pHandler.getObjects();
    if (objsPtr != nullptr) {
        for (Object *objPtr : *objsPtr) {
            vector<SDL_Vertex> *verts = objPtr->getVerts();
            if (verts != nullptr) {
                SDL_RenderGeometry(renderer, nullptr, verts->data(), verts->size(), nullptr, 0);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

// < -------------------------------------------- [ EVENT HANDLER ] ------------------------------------------------------- > \\


void Game::Events() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
            return;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_q:
                isRunning = false;
                return;
            case SDLK_p:
                pHandler.addObject();
                break;
            case SDLK_z:
                pHandler.createPrey();
                break;
            case SDLK_x:
                pHandler.createPred();
                break;
            case SDLK_c:
                pHandler.createFood();
                break;
            case SDLK_SPACE:
                pHandler.create();
                break;
            }
        }
    }
}