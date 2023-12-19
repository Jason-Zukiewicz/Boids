#include "game.hpp"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(true)
{
    window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window && renderer)
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
        if (!objs.empty())
        {
            handler.setObjects(&objs);
            handler.check();
        }

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
                case SDLK_UP:
                    // Handle UP arrow key press
                    break;
                case SDLK_DOWN:
                    // Handle DOWN arrow key press
                    break;
                    // Add cases for other keys as needed
                case SDLK_q:
                    return;
                case SDLK_p:
                    rand() % ((100 - 5) + 1) + 5;
                    int x = rand() % ((WIDTH - 0) + 1);
                    int y = rand() % ((HEIGHT - 0) + 1);
                    int w = rand() % ((100 - 5) + 1) + 5;
                    int h = rand() % ((100 - 5) + 1) + 5;
                    int r = rand() % ((255 - 0) + 1);
                    int g = rand() % ((255 - 0) + 1);
                    int b = rand() % ((255 - 0) + 1);
                    int a = 255;

                    Object obj(x, y, w, h, r, g, b, a);
                    objs.push_back(obj);
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

    for (Object &obj : objs) // Iterate by reference to avoid making copies
    {

        Color color = obj.getColor();
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, obj.getRect());
    }

    SDL_RenderPresent(renderer);
}