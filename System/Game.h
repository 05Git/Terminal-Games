#ifndef GAME_H
#define GAME_H

#include "../Entities/Entity.h"
#include "../Input/InputHandler.h"
#include <linux/input.h>

#define MAX_NUM_ENTITIES 999
#define MAX_NUM_INPUT_HANDLERS 4

typedef struct {
    // Some kind of enum containing game type (snake, frogger, etc)
    Entity **entities; // Array of entities in game
    InputHandler **inputHandlers;
    int keys[KEY_MAX];
} Game;

// Object constructor + destructor
Game *makeGame();
void destGame(Game *game);

// Core game loop functions
void input(Game *game);
void update(Game *game);
void render(Game *game);

#endif