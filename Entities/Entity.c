#include "Entity.h"
#include <stdio.h>
#include <stdlib.h>

Entity *makeEntity(void *owner, char sprite, Vector2 initPos,
                   StateMachine *sm) {
    Entity *obj = malloc(sizeof(Entity));
    obj->sprite = sprite;
    obj->sm = sm;
    obj->position = initPos;
    obj->velocity = (Vector2){0, 0};
    obj->isActive = 0;
    return obj;
}

void destEntity(Entity *obj) {
    if (obj->sm)
        free(obj->sm);

    free(obj);
}

// this actually overlaps with Game obj responsibilities,
// clean this up in future
void draw(Entity *obj) {
    if (obj->isActive >= 1) {
        printf("\033[%d;%dH", obj->position.x, obj->position.y);
        printf("%c", obj->sprite);
    }
}

void updateEntity(Entity *obj) {
    if (obj->isActive) {
        if (obj->sm)
            SMUpdate(obj->sm);

        addvec2(&obj->position, &obj->velocity);
    }
}
