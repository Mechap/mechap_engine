#ifndef _VEC2_H
#define _VEC2_H

struct vec2 {
    int x;
    int y;
    
    // NOTE(mechap): func ptrs
    void (*add_func)(struct vec2*, int, int);
    void (*sub_func)(struct vec2*, int, int);
    void (*mul_func)(struct vec2*, int);
    void (*div_func)(struct vec2*, int);
};
typedef struct vec2 Vec2;

Vec2 createVec2(int x, int y);

// NOTE(mechap): += operator
static void addVec2(Vec2 *vec, int x, int y);

// NOTE(mechap): -= operator
static void substractVec2(Vec2 *vec, int x, int y);

// NOTE(mechap): *= operator
static void multiplyVec2(Vec2 *vec, int s);

// NOTE(mechap): /= operator
static void divideVec2(Vec2 *vec, int s);

#endif //_VEC2_H
