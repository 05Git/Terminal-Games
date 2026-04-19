#include "InputHandler.h"
#include <stdlib.h>

InputHandler *makeInputHandler(void *owner, int bufferSize) {
    InputHandler *ih = malloc(sizeof(InputHandler));
    ih->owner = owner;
    ih->b_head = 0;
    ih->b_tail = 0;
    if (bufferSize > MAX_INPUT_BUFFER_SIZE)
        bufferSize = MAX_INPUT_BUFFER_SIZE;
    ih->inputBufferSize = bufferSize;
    ih->inputBuffer = calloc(ih->inputBufferSize, sizeof(Input *));
    ih->lastInput = NULL;
    return ih;
}

void destInputHandler(InputHandler *ih) {
    int i;
    for (i = 0; i < ih->inputBufferSize; i++) {
        if (ih->inputBuffer[i])
            free(ih->inputBuffer[i]);
    }
    free(ih->inputBuffer);
    free(ih);
}

void updateIH(InputHandler *ih) {
    if (ih->b_tail == ih->b_head)
        return;
    Input *nextInput = ih->inputBuffer[ih->b_tail];
    if (nextInput && (!ih->lastInput || nextInput->key != ih->lastInput->key)) {
        nextInput->Execute();
        ih->lastInput = nextInput;
    }
    ih->b_tail = (ih->b_tail + 1) % ih->inputBufferSize;
}

void addToIHBuffer(InputHandler *ih, Input *input) {
    if ((ih->b_head + 1) % ih->inputBufferSize == ih->b_tail)
        return;
    ih->inputBuffer[ih->b_head] = input;
    ih->b_head = (ih->b_head + 1) % ih->inputBufferSize;
}