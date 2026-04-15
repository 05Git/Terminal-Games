#include "GameObject.h"
#include "Physics/Vector2.h"
#include "StateMachine.h"
#include <stdio.h>
#include <stdlib.h>

GameObject *makeGameObject(void *owner, char sprite, Vector2 initPos,
                           StateMachine *sm) {
    GameObject *gameObject = malloc(sizeof(GameObject));

    gameObject->sprite = sprite;

    gameObject->sm = sm;

    gameObject->position = initPos;

    Vector2 initVelocity = {0, 0};
    gameObject->velocity = initVelocity;

    gameObject->isActive = 0;

    return gameObject;
}

void destGameObject(GameObject *obj) {
    if (obj->sm)
        free(obj->sm);

    free(obj);
}

// this actually overlaps with Game obj responsibilities,
// clean this up in future
void draw(GameObject *obj) {
    if (obj->isActive >= 1) {
        printf("\033[%d;%dH", obj->position.x, obj->position.y);
        printf("%c", obj->sprite);
    }
}

void update(GameObject *obj) {
    if (obj->sm)
        SMUpdate(obj->sm);

    addvec2(&obj->position, &obj->velocity);
}
