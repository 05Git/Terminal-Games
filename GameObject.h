#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Physics/Vector2.h"
#include "StateMachine.h"

typedef struct {
    void *owner;
    char sprite;
    StateMachine *sm;
    Vector2 position; // Should replace with physics component
    Vector2 velocity;
    unsigned int isActive;
} GameObject;

GameObject *makeGameObject(void *owner, char sprite, Vector2 initPos,
                           StateMachine *sm);

void destGameObject(GameObject *obj);

void draw(GameObject *obj);

void update(GameObject *obj);

#endif
