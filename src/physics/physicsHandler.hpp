
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

    vector<Object> *getObjects();
    void Update();
    void onScreen(Object *obj);
    void checkCollision();
    bool isColliding(Object *obj1, Object *obj2);

    void addObject();
    void addMovingObject();
    void addStationaryObject();

private:
};
