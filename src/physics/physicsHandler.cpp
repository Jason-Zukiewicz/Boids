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
    const size_t extraRows = 2;
    const size_t extraCols = 2;

    size_t numRows = static_cast<size_t>(std::ceil(HEIGHT / SIZE)) + extraRows;
    size_t numCols = static_cast<size_t>(std::ceil(WIDTH / SIZE)) + extraCols;
    vector<vector<vector<Object *>>> grid(numRows, vector<vector<Object *>>(numCols));

    for (Object *obj : objs) {
        SDL_FPoint objPos = obj->getPosition();

        // Calculate the cell indices for the object's position
        int col = static_cast<int>(std::floor(objPos.x / SIZE));
        int row = static_cast<int>(std::floor(objPos.y / SIZE));

        // Check if the object is within the grid bounds
        if (row >= 0 && row < static_cast<int>(numRows) && col >= 0 && col < static_cast<int>(numCols)) {
            // Add the object to the corresponding cell in the grid
            grid[std::max(0, row)][std::max(0, col)].push_back(obj);
            // printf("OBJECT: Put at %d, %d \n", col, row);
        } else {
            // Handle out-of-bounds objects by placing them in the additional rows and columns
            int correctedRow = std::min(std::max(0, row), static_cast<int>(numRows) - 1);
            int correctedCol = std::min(std::max(0, col), static_cast<int>(numCols) - 1);
            grid[correctedRow][correctedCol].push_back(obj);
            // printf("OBJECT: Out of bounds, put at %d, %d \n", correctedCol, correctedRow);
        }
    }

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

void PhysicsHandler::create() {
    for (int i = 0; i < 100; i++) {
        objs.push_back(new Prey(WIDTH / 4, HEIGHT / 2));
        objs.push_back(new Pred(WIDTH / 1.33, HEIGHT / 2));
    }
}