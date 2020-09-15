#include "Vec2.h"

Vec2 createVec2(int x, int y) {
    Vec2 vec = {x, y};
    return vec;
}

void addVec2(Vec2 *vec, int x, int y) {
    vec->x += x;
    vec->y += y;
}

void substractVec2(Vec2 *vec, int x, int y) {
    vec->x -= x;
    vec->y -= y;
}