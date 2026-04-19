#include "Input.h"
#include <linux/input-event-codes.h>
#include <stdlib.h>

Input *makeInput(int key, void (*ExecFn)()) {
    if (key > KEY_MAX)
        return NULL;
    Input *input = malloc(sizeof(Input));
    input->key = key;
    input->Execute = ExecFn;
    return input;
}

// This function might be useless tbh
void destInput(Input *input) { free(input); }