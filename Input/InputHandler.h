#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

typedef enum { UP, DOWN, LEFT, RIGHT, ESC } Inputs;

typedef void (*ActionFn)();

typedef struct {
    Inputs key;
    unsigned int isPressed;
    void (*ActionFn)();
} Input;

typedef struct {
    void *owner;
    Input *inputs;
} InputHandler;

InputHandler *makeInputHandler(void *owner, Input *(inpfunc)());
void destInputHandler(InputHandler *handler);

#endif
