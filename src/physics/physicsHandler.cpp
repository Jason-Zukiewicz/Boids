#include "physicsHandler.hpp"

PhysicsHandler::PhysicsHandler(int w, int h) : WIDTH(w), HEIGHT(h) {
    objs.clear();
}

PhysicsHandler::~PhysicsHandler() {}

void PhysicsHandler::Update() {
    for (auto &obj : objs) {
        obj.Update();
    }
}

void PhysicsHandler::addObject() {
    int x = rand() % ((WIDTH - 0) + 1);
    int y = rand() % ((HEIGHT - 0) + 1);
    int w = rand() % ((100 - 5) + 1) + 5;
    int h = rand() % ((100 - 5) + 1) + 5;
    int r = rand() % ((255 - 0) + 1);
    int g = rand() % ((255 - 0) + 1);
    int b = rand() % ((255 - 0) + 1);
    int a = 255;

    Object obj(x, y, w, h, r, g, b, a);
    obj.vel.y = 0.5;
    objs.push_back(obj);
}
vector<Object> *PhysicsHandler::getObjects() {
    return &objs;
}
