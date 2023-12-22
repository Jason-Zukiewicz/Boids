
#pragma once

#include "object/food.hpp"
#include "object/object.hpp"
#include "object/pred.hpp"
#include "object/prey.hpp"
#include <cmath>
#include <random>
#include <vector>
using std::vector;

class PhysicsHandler {
public:
    vector<Object *> objs;
    int WIDTH;
    int HEIGHT;

private:
public:
    PhysicsHandler(int w, int h);
    ~PhysicsHandler();

    vector<Object *> *getObjects();
    void Update();

    void onScreen(Object *obj);
    void checkCollision();

    // bool isColliding(Object *obj1, Object *obj2);

    void addObject();
    void createPrey();
    void createPred();
    void createFood();
    void create();

private:
};
