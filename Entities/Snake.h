#ifndef SNAKE_H
#define SNAKE_H

#include "../GameObject.h"
#include "../Input/InputHandler.h"

typedef struct {
    GameObject *object;
    State *snakeStates;
    InputHandler *inputHandler;
} Snake;

Snake *makeSnake();
void destSnake(Snake *snake);

int moveLeftCond(void *owner);
int moveRightCond(void *owner);
int moveUpCond(void *owner);
int moveDownCond(void *owner);

static State left, right, up, down;

static Transition leftTransitions[] = {
    {moveRightCond, &right}, {moveUpCond, &up}, {moveDownCond, &down}};

static Transition rightTransitions[] = {
    {moveLeftCond, &left}, {moveUpCond, &up}, {moveDownCond, &down}};

static Transition upTransitions[] = {
    {moveLeftCond, &left}, {moveRightCond, &right}, {moveDownCond, &down}};

static Transition downTransitions[] = {
    {moveLeftCond, &left}, {moveRightCond, &right}, {moveUpCond, &up}};

#endif
