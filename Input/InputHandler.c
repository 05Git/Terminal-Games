#include "InputHandler.h"
#include <stdlib.h>

InputHandler *makeInputHandler(void *owner, Input *(inpfunc)()) {
    InputHandler *handler = malloc(sizeof(InputHandler));
    handler->owner = owner;
    handler->inputs = inpfunc();
    return handler;
}

void destInputHandler(InputHandler *handler) {
    if (handler->inputs)
        free(handler->inputs);

    free(handler);
}
