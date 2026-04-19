#ifndef INPUT_H
#define INPUT_H

typedef struct {
    int key;
    void (*Execute)();
} Input;

Input *makeInput(int key, void (*ExecFn)());

void destInput(Input *input);

#endif