#include "pred.hpp"

Pred::Pred(int x, int y) : Object({x, y}, RED) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-1, 1); // Generate random floats within the specified range

    vel.x = dist(gen); // Directly use the generated random float
    vel.y = dist(gen);
}

Pred::~Pred() {
}

void Pred::Update() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-.1, .1); // Generate random floats within the specified range

    temp.x = dist(gen); // Directly use the generated random float
    temp.y = dist(gen);

    acc.x += temp.x;
    acc.y += temp.y;

    vel.x += acc.x;
    vel.y += acc.y;

    float mag = sqrt(vel.x * vel.x + vel.y * vel.y);
    SDL_FPoint norm = {0.0f, 0.0f};
    if (mag != 0) {
        norm.x = vel.x = vel.x / mag;
        norm.y = -vel.y / mag;
        vel.y = -norm.y;
    }

    pos.x += vel.x;
    pos.y += vel.y;

    float hSize = SIZE / 2;

    // Position vertex 0 at the tip of the triangle
    verts[0].position.x = pos.x + norm.x * hSize;
    verts[0].position.y = pos.y - norm.y * hSize; // Invert y-axis relative to pos.y

    // Position vertices 1 and 2 on the other side of the velocity vector
    verts[1].position.x = pos.x - norm.x * hSize - norm.y * hSize / 2;
    verts[1].position.y = pos.y + norm.y * hSize / 2 - norm.x * hSize / 2;

    verts[2].position.x = pos.x - norm.x * hSize + norm.y * hSize / 2;
    verts[2].position.y = pos.y + norm.y * hSize / 2 + norm.x * hSize / 2;
}