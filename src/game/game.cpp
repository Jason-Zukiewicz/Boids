#include "game.hpp"

Game::Game() : isRunning(true), window(nullptr), renderer(nullptr), pHandler(WIDTH, HEIGHT)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("[ERROR] Could Not INIT SDL\n");
        return;
    }

    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    if (!window)
    {
        printf("[ERROR] Could Not Create Window\n");
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window)
    {
        printf("[ERROR] Could Not Create Renderer\n");
        return;
    }

    Run();
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Run()
{
    while (isRunning)
    {

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                // Handle quit event (e.g., user closing the window)
                return;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                // Handle key press event
                switch (event.key.keysym.sym)
                {
                case SDLK_q:
                    return;
                case SDLK_p:
                    pHandler.addObject();
                    break;
                }
            }
        }

        Update();
        Draw();
    }
}

void Game::Update()
{
    // printf("INSIDE Update\n");
}

void Game::Draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    vector<Object> *objs = pHandler.getObjects();
    if (objs != nullptr)
    {
        for (Object &obj : *objs)
        {
            Color color = obj.getColor();
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_Rect *rect = obj.getRect();
            SDL_RenderFillRect(renderer, rect);
        }
    }

    SDL_RenderPresent(renderer);
}