#include "Vector2.h"

void addvec2(Vector2 *a, Vector2 *b) {
    a->x += b->x;
    a->y += b->y;
}

void multvec2(Vector2 *a, float z) {
    a->x *= z;
    a->y *= z;
}

void subvec2(Vector2 *a, Vector2 *b) {
    a->x -= b->x;
    a->y -= b->y;
}

void divvec2(Vector2 *a, float z) {
    a->x /= z;
    a->y /= z;
}
