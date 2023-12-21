#include "physicsHandler.hpp"

PhysicsHandler::PhysicsHandler(int w, int h) : WIDTH(w), HEIGHT(h) {
    objs.clear();
}

PhysicsHandler::~PhysicsHandler() {
    for (auto obj : objs)
        delete obj;
}

void PhysicsHandler::Update() {
    checkCollision();
    for (auto &obj : objs) {
        obj->Update();
    }
}

vector<Object *> *PhysicsHandler::getObjects() {
    return &objs;
}

// < ----------------------------------- [ Collision ] -----------------------------------------> \\


void PhysicsHandler::onScreen(Object *obj) {
    if (obj->pos.x < 0) {
        obj->vel.x = -obj->vel.x;
    } else if (obj->pos.x > WIDTH) {
        obj->vel.x = -obj->vel.x;
    }

    if (obj->pos.y < 0) {
        obj->vel.y = -obj->vel.y;
    } else if (obj->pos.y > HEIGHT) {
        obj->vel.y = -obj->vel.y;
    }
}

/*
bool PhysicsHandler::isColliding(Object *obj1, Object *obj2) {
    return SDL_HasIntersection(&(obj1->rect), &(obj2->rect)) == SDL_TRUE;
}
*/

void PhysicsHandler::checkCollision() {
    for (size_t i = 0; i < objs.size(); ++i)
        onScreen(objs[i]);

    /*
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
    */
}

// < ----------------------------------- [ OBJECT CREATION ] -----------------------------------------> \\

void PhysicsHandler::createPrey() {
    objs.push_back(new Prey(WIDTH / 4, HEIGHT / 2));
}

void PhysicsHandler::createPred() {
    objs.push_back(new Pred(WIDTH / 1.33, HEIGHT / 2));
}

void PhysicsHandler::createFood() {
    objs.push_back(new Food(WIDTH / 2, HEIGHT / 2));
}

void PhysicsHandler::addObject() {
    objs.push_back(new Object(WIDTH / 2, HEIGHT / 2));
}