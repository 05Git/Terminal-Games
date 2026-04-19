#ifndef STATEMACHINE_H
#define STATEMACHINE_H

typedef struct State State;
typedef struct StateMachine StateMachine;

typedef int (*ConditionFn)(void *owner);

typedef struct {
    ConditionFn condition;
    State *nextState;
} Transition;

typedef struct State {
    void (*onEnter)(void *owner);
    void (*onUpdate)(void *owner);
    void (*onExit)(void *owner);

    Transition *transitions;
    unsigned int numTransitions;

    StateMachine *subSM; // Optional - Enables hierarchical FSM
} State;

typedef struct StateMachine {
    State *currentState;
    void *owner;
} StateMachine;

StateMachine *makeStateMachine(void *owner, State *initState);
void destStateMachine(StateMachine *sm);

void SMTransition(StateMachine *sm, State *nextState);

void SMUpdate(StateMachine *sm);

#endif
