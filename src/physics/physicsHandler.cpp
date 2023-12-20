#include "physicsHandler.hpp"

PhysicsHandler::PhysicsHandler(int w, int h) : WIDTH(w), HEIGHT(h) {
    objs.clear();
}

PhysicsHandler::~PhysicsHandler() {}

void PhysicsHandler::Update() {
    checkCollision();
    for (auto &obj : objs) {
        obj.Update();
    }
}

bool PhysicsHandler::isColliding(Object *obj1, Object *obj2) {
    return SDL_HasIntersection(&(obj1->rect), &(obj2->rect)) == SDL_TRUE;
}

void PhysicsHandler::onScreen(Object *obj) {
    if (obj->pos.x < 0) {
        obj->pos.x = WIDTH;
    } else if (obj->pos.x > WIDTH) {
        obj->pos.x = 0;
    }

    if (obj->pos.y < 0) {
        obj->pos.y = HEIGHT;
    } else if (obj->pos.y > HEIGHT) {
        obj->pos.y = 0;
    }
}

void PhysicsHandler::checkCollision() {
    for (size_t i = 0; i < objs.size(); ++i)
        onScreen(&objs[i]);

    for (size_t i = 0; i < objs.size(); ++i) {
        for (size_t j = i + 1; j < objs.size(); ++j) {
            if (isColliding(&objs[i], &objs[j])) {
                printf("COLLISION between objects %zu and %zu\n", i, j);
                objs[i].vel.x = -objs[i].vel.x;
                objs[i].vel.y = -objs[i].vel.y;
                objs[j].vel.x = -objs[j].vel.x;
                objs[j].vel.y = -objs[j].vel.y;
            }
        }
    }
}

// < ----------------------------------- [] ----------------------------------------->

void PhysicsHandler::addMovingObject() {
    Object obj(200, 300, 100, 100, 0, 0, 255, 255);
    obj.vel.x = 10;
    objs.push_back(obj);
}

void PhysicsHandler::addStationaryObject() {
    Object obj(600, 300, 100, 100, 255, 0, 0, 255);
    objs.push_back(obj);
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
    objs.push_back(obj);
}
vector<Object> *PhysicsHandler::getObjects() {
    return &objs;
}
