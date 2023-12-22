#pragma once
#include "object.hpp"

class Pred : public Object {
public:
    SDL_FPoint temp;

private:
public:
    Pred(int x, int y);
    ~Pred();

    void Update() override;

private:
};