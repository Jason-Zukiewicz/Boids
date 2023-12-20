
#pragma once

#include "object/food.hpp"
#include "object/object.hpp"
#include "object/pred.hpp"
#include "object/prey.hpp"
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

    void createPrey();
    void createPred();
    void createFood();

private:
};
