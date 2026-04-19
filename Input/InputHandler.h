#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Input.h"
#include <linux/input.h>

#define MAX_INPUT_BUFFER_SIZE 256

typedef struct {
    void *owner;
    Input **inputBuffer;
    int inputBufferSize;
    int b_head;
    int b_tail;
    Input *lastInput;
} InputHandler;

InputHandler *makeInputHandler(void *owner, int bufferSize);

void destInputHandler(InputHandler *ih);

void updateIH(InputHandler *ih);

void addToIHBuffer(InputHandler *ih, Input *input);

#endif
