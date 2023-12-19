#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "../object/object.hpp"

using std::vector;

class EventHandler
{
    SDL_Event event;
    vector<Object> *objs;

public:
    EventHandler();
    ~EventHandler();
    void check();
    void setObjects(vector<Object> *objs);

private:
};
