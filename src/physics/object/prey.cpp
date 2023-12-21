#include "prey.hpp"

Prey::Prey(int x, int y) : Object({x, y}, BLUE) {
    vel.y = -10;
}

Prey::~Prey() {
}

void Prey::Update() {

    vel.x += acc.x;
    vel.y += acc.y;

    pos.x += vel.x;
    pos.y += vel.y;

    float angle = atan2(-vel.y, vel.x);

    for (int i = 0; i < 3; ++i) {
        float dx = verts[i].position.x - pos.x;
        float dy = verts[i].position.y - pos.y;

        verts[i].position.x = pos.x + (dx * cos(angle) - dy * sin(angle));
        verts[i].position.y = pos.y + (dx * sin(angle) + dy * cos(angle));
    }
}