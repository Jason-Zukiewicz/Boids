
#pragma once

#include "object.hpp"
#include <random>
#include <vector>
using std::vector;

class PhysicsHandler {
public:
    vector<Object> objs;
    int WIDTH;
    int HEIGHT;

private:
public:
    PhysicsHandler(int w, int h);
    ~PhysicsHandler();

    void addObject();
    vector<Object> *getObjects();

private:
};
