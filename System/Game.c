#include "Game.h"
#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdlib.h>
#include <unistd.h>

Game *makeGame() {
    Game *game = malloc(sizeof(Game));
    game->entities = calloc(MAX_NUM_ENTITIES, sizeof(Entity *));
    game->inputHandlers =
        calloc(MAX_NUM_INPUT_HANDLERS, sizeof(InputHandler *));
    return game;
}

void destGame(Game *game) {
    int i;
    for (i = 0; i < MAX_NUM_ENTITIES; i++) {
        if (game->entities[i])
            destEntity(game->entities[i]);
    }
    free(game->entities);

    for (i = 0; i < MAX_NUM_INPUT_HANDLERS; i++) {
        if (game->inputHandlers[i])
            destInputHandler(game->inputHandlers[i]);
    }
    free(game->inputHandlers);

    free(game);
}

void input(Game *game) {
    // Read keyboard inputs with <linux/input.h>
    int fd = open("/dev/input/event15", O_RDONLY | O_NONBLOCK);
    if (fd != 0) {
        // do some logging, potentially crash the game
        return;
    }

    // Send registered keypresses to input handlers
    struct input_event ev;
    while (read(fd, &ev, sizeof(ev)) > 0) {
        if (ev.type == EV_KEY && ev.code > KEY_MAX) {
            // Check less than 2 to ignore autorepeat keys
            if (ev.value > 2)
                game->keys[ev.type] = ev.value;
        }
    }

    // Probably want to open/close in main file actually
    close(fd);
}

void update(Game *game) {
    // Loop through all components and call update functions
}

void render(Game *game) {
    // Loop through all drawable objects and call render function
    // Would probably be good to make a render component
}