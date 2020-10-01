#include "Vec2.h"
#include <assert.h>

Vec2 createVec2(int x, int y) {
    Vec2 vec;
    vec.x = x;
    vec.y = y;
    
    // NOTE(mechap): init methods
    vec.add_func = &addVec2;
    vec.sub_func = &substractVec2;
    vec.mul_func = &multiplyVec2;
    vec.div_func = &divideVec2;
    
    return vec;
}

//~ NOTE(mechap): static functions

static void addVec2(Vec2 *vec, int x, int y) {
    vec->x += x;
    vec->y += y;
}

static void substractVec2(Vec2 *vec, int x, int y) {
    vec->x -= x;
    vec->y -= y;
}

static void multiplyVec2(Vec2 *vec, int s) {
    vec->x *= s;
    vec->y *= s;
}

static void divideVec2(Vec2 *vec, int s) {
    assert((s == 0) && "can't divide by 0\n");
    
    vec->x /= s;
    vec->y /= s;
}