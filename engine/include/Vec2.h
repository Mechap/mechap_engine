#ifndef _VEC2_H
#define _VEC2_H

union Vec2 {
    struct {
        int x;
        int y;
    };
    int v[2];
};
typedef union Vec2 Vec2;

Vec2 createVec2(int x, int y);

// NOTE(mechap): += operator
void addVec2(Vec2 *vec, int x, int y);

// NOTE(mechap): -= operator
void substractVec2(Vec2 *vec, int x, int y);

#endif //_VEC2_H
