#include "Snake.h"
#include "../GameObject.h"
#include "../Input/InputHandler.h"
#include <stdlib.h>

static void setStates(Snake *snake) {
    static State left = {.onEnter = NULL,
                         .onUpdate = NULL,
                         .onExit = NULL,
                         .transitions = leftTransitions,
                         .numTransitions = 3,
                         .subSM = NULL};

    static State right = {.onEnter = NULL,
                          .onUpdate = NULL,
                          .onExit = NULL,
                          .transitions = rightTransitions,
                          .numTransitions = 3,
                          .subSM = NULL};

    static State up = {.onEnter = NULL,
                       .onUpdate = NULL,
                       .onExit = NULL,
                       .transitions = upTransitions,
                       .numTransitions = 3,
                       .subSM = NULL};

    static State down = {.onEnter = NULL,
                         .onUpdate = NULL,
                         .onExit = NULL,
                         .transitions = downTransitions,
                         .numTransitions = 3,
                         .subSM = NULL};

    State states[] = {up, down, left, right};
    snake->snakeStates = states;
}

Input *snakeInputs() {
    Input *inputs = malloc(sizeof(Input) * 4);
    return inputs;
}

Snake *makeSnake() {
    Snake *snake = malloc(sizeof(Snake));
    setStates(snake);
    snake->object = makeGameObject(snake, 'S', (Vector2){0, 0},
                                   makeStateMachine(snake, NULL));
    snake->inputHandler = makeInputHandler(snake, snakeInputs());

    return snake;
}

void destSnake(Snake *snake) {
    if (snake->object)
        destGameObject(snake->object);

    if (snake->snakeStates)
        free(snake->snakeStates);

    if (snake->inputHandler)
        destInputHandler(snake->inputHandler);

    free(snake);
}
