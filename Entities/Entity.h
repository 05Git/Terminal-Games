#ifndef ENTITY_H
#define ENTITY_H

#include "../Physics/Vector2.h"
#include "../System/Behaviour/StateMachine.h"

typedef struct {
    void *owner;
    char sprite;
    StateMachine *sm;
    Vector2 position; // Should replace with physics component
    Vector2 velocity;
    unsigned int isActive;
} Entity;

Entity *makeEntity(void *owner, char sprite, Vector2 initPos, StateMachine *sm);

void destEntity(Entity *obj);

void drawEntity(Entity *obj);

void updateEntity(Entity *obj);

#endif
