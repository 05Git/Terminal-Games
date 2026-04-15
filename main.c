/*
 * DUNGEON - A game about crawling around a dungeon and slowly growing
 * a party of adventurers over time. Start as a snake-like, then work
 * upward to more complex game styles.
 */

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define HEIGHT 30
#define WIDTH 80
#define CENTRE_X HEIGHT / 2
#define CENTRE_Y WIDTH / 2

#define WALL '#'
#define S_HEAD 'S'
#define S_BODY 'o'
#define APPLE '@'

struct sys_info {
    struct winsize init_w;
};

struct sys_info SYS;

void draw() {
    printf("\033[H");  // Set cursor pos to (0,0)
    printf("\033[1J"); // Clear screen
    printf("\033[0m"); // Reset text modes
    fflush(stdout);    // Flush stdout to call ansi cmds
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (x == 0 || y == 0 || x == WIDTH - 1 || y == HEIGHT - 1)
                printf("%c", WALL);
            else
                printf(" ");
        }
        if (y <= HEIGHT - 2)
            printf("\n");
    }
}

int init() {
    int io_res = ioctl(STDOUT_FILENO, TIOCGWINSZ, &SYS.init_w);

    if (io_res == -1)
        return -1;

    printf("\033[8;%d;%dt", HEIGHT, WIDTH);
    fflush(stdout);

    draw();

    printf("\033[%d;%dH", CENTRE_X, CENTRE_Y - 4);
    printf("\033[5mGAME START");
    fflush(stdout);

    sleep(4);

    return 0;
}

int main(int argc, char *argv[]) {
    int init_ret_code = init();
    if (init_ret_code != 0) {
        printf("Bad init code: %d\n", init_ret_code);
        return init_ret_code;
    }

    int iters = 0;
    while (iters < 10) {
        // TODO: Add game loop (input, update, draw)
        draw();
        iters++;
    }

    printf("\033[%d;%dH", CENTRE_X, CENTRE_Y - 4);
    printf("\033[5mGAME OVER");
    fflush(stdout);

    sleep(4);

    printf("\033[8;%d;%dt", SYS.init_w.ws_col, SYS.init_w.ws_row);
    printf("\033[H");
    printf("\033[1J");
    fflush(stdout);
    return 0;
}
