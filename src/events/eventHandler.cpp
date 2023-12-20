#include "eventHandler.hpp"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::check()
{

    /*
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            // Handle quit event (e.g., user closing the window)
            return false;
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
                return false;
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
     */
}
/*
void EventHandler::setObjects(vector<Object> *objsPtr)
{
    objs = objsPtr;
}
*/