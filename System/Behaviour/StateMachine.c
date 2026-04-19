#include "StateMachine.h"
#include <stdlib.h>

StateMachine *makeStateMachine(void *owner, State *initState) {
    StateMachine *sm = malloc(sizeof(StateMachine));
    sm->currentState = initState;
    sm->owner = owner;
    return sm;
}

void destStateMachine(StateMachine *sm) {
    if (sm->currentState)
        free(sm->currentState);

    free(sm);
}

void SMTransition(StateMachine *sm, State *nextState) {
    if (sm->currentState) {
        // Trigger onExit logic of subSM
        if (sm->currentState->subSM)
            SMTransition(sm->currentState->subSM, NULL);

        if (sm->currentState->onExit)
            sm->currentState->onExit(sm->owner);
    }

    sm->currentState = nextState;
    if (sm->currentState) {
        if (sm->currentState->onEnter)
            sm->currentState->onEnter(sm->owner);

        // Trigger onEntry logic of subSM
        if (sm->currentState->subSM)
            SMTransition(sm->currentState->subSM,
                         sm->currentState->subSM->currentState);
    }
}

void SMUpdate(StateMachine *sm) {
    if (!sm->currentState)
        return;

    // Fire subSM first, then Top level SM
    if (sm->currentState->subSM)
        SMUpdate(sm->currentState->subSM);

    if (sm->currentState->onUpdate)
        sm->currentState->onUpdate(sm->owner);

    // Loops through state's T array and fires first one that triggers
    // Might want to put in some priority
    for (int i = 0; i < sm->currentState->numTransitions; i++) {
        Transition *t = &sm->currentState->transitions[i];
        // TODO: Check transition logic
        if (t->condition && t->condition(sm->owner)) {
            SMTransition(sm, t->nextState);
            break;
        }
    }
}
