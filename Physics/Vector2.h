#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct {
    int x;
    int y;
} Vector2;

void addvec2(Vector2 *a, Vector2 *b);

void subvec2(Vector2 *a, Vector2 *b);

void multvec2(Vector2 *a, float z);

void divvec2(Vector2 *a, float z);

#endif
