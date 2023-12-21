#include "object.hpp"

Object::Object()
    : pos{0, 0}, vel{0, 0}, acc{0, 0} {
}

Object::Object(int x, int y)
    : pos{x, y}, vel{0, 0}, acc{0, 0} {

    int x1, x2, x3, y1, y2, y3;
    x1 = x;
    y1 = y - SIZE;

    x2 = x - SIZE / 2;
    y2 = y + SIZE / 2;

    x3 = x + SIZE / 2;
    y3 = y + SIZE / 2;

    verts =
        {
            {
                SDL_FPoint{x1, y1},
                SDL_Color{255, 255, 255, 255},
                SDL_FPoint{0, 0},
            },
            {
                SDL_FPoint{x2, y2},
                SDL_Color{255, 255, 255, 255},
                SDL_FPoint{0, 0},
            },
            {
                SDL_FPoint{x3, y3},
                SDL_Color{255, 255, 255, 255},
                SDL_FPoint{0, 0},
            },
        };
}

Object::Object(int x, int y, int r, int g, int b, int a)
    : pos{x, y}, vel{0, 0}, acc{0, 0} {
}

Object::Object(SDL_FPoint point, SDL_Color color)
    : pos{point.x, point.y}, vel{0, 0}, acc{0, 0} {

    int x1, x2, x3, y1, y2, y3;
    x1 = point.x;
    y1 = point.y - SIZE;

    x2 = point.x - SIZE / 2;
    y2 = point.y + SIZE / 2;

    x3 = point.x + SIZE / 2;
    y3 = point.y + SIZE / 2;

    verts =
        {
            {
                SDL_FPoint{x1, y1},
                color,
                SDL_FPoint{0, 0},
            },
            {
                SDL_FPoint{x2, y2},
                color,
                SDL_FPoint{0, 0},
            },
            {
                SDL_FPoint{x3, y3},
                color,
                SDL_FPoint{0, 0},
            },
        };
}

Object::~Object() {}

vector<SDL_Vertex> *Object::getVerts() {
    return &verts;
}

void Object::Update() {
    vel.x += acc.x;
    vel.y += acc.y;

    pos.x += vel.x;
    pos.y += vel.y;

    verts[0].position.x += vel.x;
    verts[0].position.y += vel.y;

    verts[1].position.x += vel.x;
    verts[1].position.y += vel.y;

    verts[2].position.x += vel.x;
    verts[2].position.y += vel.y;
}

SDL_FPoint Object::getPosition() {
    return pos;
}

SDL_FPoint Object::getNextPosition() {
    return {pos.x + vel.x + acc.x, pos.y + vel.y + acc.y};
}